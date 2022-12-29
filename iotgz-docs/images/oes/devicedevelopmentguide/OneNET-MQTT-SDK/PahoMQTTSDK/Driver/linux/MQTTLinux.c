/*******************************************************************************
 * Copyright (c) 2014, 2017 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Allan Stockdill-Mander - initial API and implementation and/or initial documentation
 *    Ian Craggs - return codes from linux_read
 *******************************************************************************/

#include "MQTTLinux.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/debug.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/error.h"
#include "mbedtls/certs.h"

#define DBG printf
//#define USE_TLS
typedef struct {
    mbedtls_ssl_context ssl_ctx;        /* mbedtls ssl context */
    mbedtls_net_context net_ctx;        /* Fill in socket id */
    mbedtls_ssl_config ssl_conf;        /* SSL configuration */
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_x509_crt_profile profile;
    mbedtls_x509_crt cacert;
    mbedtls_x509_crt clicert;
    mbedtls_pk_context pkey;
} tls_t;
const char ca_cert[] =
{"-----BEGIN CERTIFICATE-----\r\n"\
"MIID9TCCAt2gAwIBAgIJAIxExH3A7YtAMA0GCSqGSIb3DQEBCwUAMIGQMQswCQYD\r\n"\
"VQQGEwJjbjELMAkGA1UECAwCY3ExFTATBgNVBAcMDERlZmF1bHQgQ2l0eTEcMBoG\r\n"\
"A1UECgwTRGVmYXVsdCBDb21wYW55IEx0ZDEOMAwGA1UECwwFY21pb3QxEzARBgNV\r\n"\
"BAMMCjEwLjEyLjQuMjUxGjAYBgkqhkiG9w0BCQEWC3Rlc3RAcXEuY29tMB4XDTE5\r\n"\
"MDgwMTAzNDk1M1oXDTI0MDczMTAzNDk1M1owgZAxCzAJBgNVBAYTAmNuMQswCQYD\r\n"\
"VQQIDAJjcTEVMBMGA1UEBwwMRGVmYXVsdCBDaXR5MRwwGgYDVQQKDBNEZWZhdWx0\r\n"\
"IENvbXBhbnkgTHRkMQ4wDAYDVQQLDAVjbWlvdDETMBEGA1UEAwwKMTAuMTIuNC4y\r\n"\
"NTEaMBgGCSqGSIb3DQEJARYLdGVzdEBxcS5jb20wggEiMA0GCSqGSIb3DQEBAQUA\r\n"\
"A4IBDwAwggEKAoIBAQCt4eKgklFkPnYct+27RTiEXvYd4Iwe8Rm/FXMKawFJsYbn\r\n"\
"LKHOSxSZgFYr7tIludmWBmmRprtuBB9dkO8vM1Db1HbJEto0RM7CbSGaIlSGi5ZA\r\n"\
"TDqAsK/4I5b300icVpqCk61QLr01t3yCyobYSKxT2KVjbYFnVz3MXScc8SBWYAum\r\n"\
"roZtvl7b/lijHzsWncFOEhtb7UhW2r+BiCuKobqIC0PZxAtny9mip17yyykHvD9C\r\n"\
"Imvl/QxPqZw21ws/6cvQ1D7zhCdxXfN6Rl/2PoEIiKryoYD94646iaPKIwnvL1WI\r\n"\
"IWBi1Lsk0rwok9H5Czyd1ol504dNZXcIp2csxrLnAgMBAAGjUDBOMB0GA1UdDgQW\r\n"\
"BBSMwNSx2ghG6tU1oKMDoHbMNbVwTTAfBgNVHSMEGDAWgBSMwNSx2ghG6tU1oKMD\r\n"\
"oHbMNbVwTTAMBgNVHRMEBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQALi1gMHpxy\r\n"\
"NtvSbpoGGj3R33mU7u/RMVdQFudtRVlT7REMwUrDBuOM+yYBJNk7oojRFrJa/Qe2\r\n"\
"P5SljOALgJIQnnpDRAGK+tOrTTSPucuSdfu7rmIR2OyFyfvXfTgafMqZvH9JxXgK\r\n"\
"B2nk3ht1I5LLMvjzsVjxnclfosBdrzt6v4vDjF+dObd+GAnG5Oa07O6nMVHzb+KW\r\n"\
"DpQMdxKqEdnJNLpZOCZtbjONMVY6EPpoBCSyBwwNiutAliEnmIs4TzAjnaAjsXgt\r\n"\
"9G9TA99lJvweMqdXDmNPCX5ZAe0rm87eGBgLvp4B66lPChpHKT8Cbiu9WjWqyJpP\r\n"\
"bdAkTM11q1Y9\r\n"\
"-----END CERTIFICATE-----\r\n"};

void TimerInit(Timer* timer)
{
	timer->end_time = (struct timeval){0, 0};
}

char TimerIsExpired(Timer* timer)
{
	struct timeval now, res;
	gettimeofday(&now, NULL);
	timersub(&timer->end_time, &now, &res);
	return res.tv_sec < 0 || (res.tv_sec == 0 && res.tv_usec <= 0);
}


void TimerCountdownMS(Timer* timer, unsigned int timeout)
{
	struct timeval now;
	gettimeofday(&now, NULL);
	struct timeval interval = {timeout / 1000, (timeout % 1000) * 1000};
	timeradd(&now, &interval, &timer->end_time);
}


void TimerCountdown(Timer* timer, unsigned int timeout)
{
	struct timeval now;
	gettimeofday(&now, NULL);
	struct timeval interval = {timeout, 0};
	timeradd(&now, &interval, &timer->end_time);
}


int TimerLeftMS(Timer* timer)
{
	struct timeval now, res;
	gettimeofday(&now, NULL);
	timersub(&timer->end_time, &now, &res);
	//printf("left %d ms\n", (res.tv_sec < 0) ? 0 : res.tv_sec * 1000 + res.tv_usec / 1000);
	return (res.tv_sec < 0) ? 0 : res.tv_sec * 1000 + res.tv_usec / 1000;
}


int linux_read(Network* n, unsigned char* buffer, int len, int timeout_ms)
{
	struct timeval interval = {timeout_ms / 1000, (timeout_ms % 1000) * 1000};
	if (interval.tv_sec < 0 || (interval.tv_sec == 0 && interval.tv_usec <= 0))
	{
		interval.tv_sec = 0;
		interval.tv_usec = 100;
	}

	setsockopt(n->my_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&interval, sizeof(struct timeval));

	int bytes = 0;
	while (bytes < len)
	{
		int rc = recv(n->my_socket, &buffer[bytes], (size_t)(len - bytes), 0);
		if (rc == -1)
		{
			if (errno != EAGAIN && errno != EWOULDBLOCK)
			  bytes = -1;
			break;
		}
		else if (rc == 0)
		{
			bytes = 0;
			break;
		}
		else
			bytes += rc;
	}
	return bytes;
}


int linux_write(Network* n, unsigned char* buffer, int len, int timeout_ms)
{
	struct timeval tv;

	tv.tv_sec = 0;  /* 30 Secs Timeout */
	tv.tv_usec = timeout_ms * 1000;  // Not init'ing this can cause strange errors

	setsockopt(n->my_socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv,sizeof(struct timeval));
	int	rc = write(n->my_socket, buffer, len);
	return rc;
}

int ca_cert_init(Network* n)
{
	if(n)
	{
		n->server_cert = ca_cert;
		n->server_cert_len = sizeof(ca_cert);
		if(!n->tls)
		{
			n->tls = malloc(sizeof(tls_t));
			if(!n->tls)
			{
				printf("n->tls is NULL");
				return -1;
			}
			memset(n->tls,0,sizeof(tls_t));
			
		}
		return 0;
	}
	return -1;
}

static int tls_linux_read(Network* n, unsigned char* buffer, int len, int timeout_ms)
{
	tls_t *tls = (tls_t *)n->tls;
	if(tls)
	{
		int ret = mbedtls_ssl_read(&tls->ssl_ctx, buffer, len);
#if 0
		printf("mbedtls_ssl_read %d bytes:",len);
		int i = 0;
		for(i = 0;i < len;i++)
		{
			printf(" %02X",buffer[i]);
		}
		printf("\r\n");
#endif
		return ret;
	}
	return -1;
}
static int tls_linux_write(Network* n, unsigned char* buffer, int len, int timeout_ms)
{
	tls_t *tls = (tls_t *)n->tls;
	if(tls)
	{
		int ret = mbedtls_ssl_write(&tls->ssl_ctx, buffer, len);
#if 0
		printf("mbedtls_ssl_write %d bytes:",len);
		int i = 0;
		for(i = 0;i < len;i++)
		{
			printf(" %02X",buffer[i]);
		}
		printf("\r\n");
#endif
		return ret;
	}
	return -1;
}

void NetworkInit(Network* n)
{
#ifdef USE_TLS
	n->mqttread = tls_linux_read;
	n->mqttwrite = tls_linux_write;
#else
	n->my_socket = 0;
	n->mqttread = linux_read;
	n->mqttwrite = linux_write;
#endif
}

static void mytls_debug( void *ctx, int level, const char *file, int line, const char *str )
{  
    DBG("%s\r\n", str);
}
static int tls_tcp_connect(Network* n, char* host, int port) 
{
	int authmode = MBEDTLS_SSL_VERIFY_NONE;
	int ret = 0;
	int flags = 0;
	char porta[10] = {0};
	const char *pers = "mqtt";
	tls_t *ssl;
	
	if(ca_cert_init(n) != 0)
	{
		ret = -1;
		goto exit;
	}
	ssl = (tls_t *)n->tls;
	if(!ssl)
	{
		ret = -1;
		goto exit;
	}
    if (n->server_cert)
        authmode = MBEDTLS_SSL_VERIFY_REQUIRED;
	/*
     * Initialize the RNG and the session data
     */
	mbedtls_net_init(&ssl->net_ctx);
    mbedtls_ssl_init(&ssl->ssl_ctx);
    mbedtls_ssl_config_init(&ssl->ssl_conf);
    mbedtls_x509_crt_init(&ssl->cacert);
    mbedtls_x509_crt_init(&ssl->clicert);
    mbedtls_pk_init(&ssl->pkey);
    mbedtls_ctr_drbg_init(&ssl->ctr_drbg);
    mbedtls_entropy_init(&ssl->entropy); 
	if ((ret = mbedtls_ctr_drbg_seed(&ssl->ctr_drbg,
               mbedtls_entropy_func, 
               &ssl->entropy,
               (const unsigned char*)pers,
               strlen(pers))) != 0)
   {
		printf( " failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret );
		goto exit;
   }
	/*
	* Load the Client certificate
	*/
	if (n->client_cert && n->client_pk) {
	    ret = mbedtls_x509_crt_parse(&ssl->clicert, (const unsigned char *)n->client_cert, n->client_cert_len);        
	    if (ret < 0) {
	        DBG("Loading cli_cert failed! mbedtls_x509_crt_parse returned -0x%x.", -ret);
	        goto exit;
	    }

	    ret = mbedtls_pk_parse_key(&ssl->pkey, (const unsigned char *)n->client_pk, n->client_pk_len, NULL, 0);                 
	    if (ret != 0) {
	        DBG("failed! mbedtls_pk_parse_key returned -0x%x.", -ret);
	        goto exit;
	    }
	}	
    /*
    * Load the trusted CA
    */    
    /* cert_len passed in is gotten from sizeof not strlen */
    if (n->server_cert && ((ret = mbedtls_x509_crt_parse(&ssl->cacert,
                                        (const unsigned char *)n->server_cert,
                                        n->server_cert_len)) < 0)) {
        DBG("mbedtls_x509_crt_parse() failed, value:-0x%x.", -ret);
        ret = -1;
        goto exit;
    }
	 /*
	 * Start the connection
	 */
	
	snprintf(porta, sizeof(porta), "%d", port) ;
    if ((ret = mbedtls_net_connect(&ssl->net_ctx, host, porta, MBEDTLS_NET_PROTO_TCP)) != 0) {
        DBG("failed! mbedtls_net_connect returned %d, port:%s.", ret, porta);
        goto exit;
    }   
    /*
     * Setup stuff
     */
    if ((ret = mbedtls_ssl_config_defaults(&ssl->ssl_conf,
                                           MBEDTLS_SSL_IS_CLIENT,
                                           MBEDTLS_SSL_TRANSPORT_STREAM,
                                           MBEDTLS_SSL_PRESET_DEFAULT)) != 0) {        
        DBG("mbedtls_ssl_config_defaults() failed, value:-0x%x.", -ret);
        ret = -1;
        goto exit;
    }

	mbedtls_ssl_conf_authmode( &ssl->ssl_conf, authmode );
	mbedtls_ssl_conf_ca_chain(&ssl->ssl_conf, &ssl->cacert, NULL);
	mbedtls_ssl_conf_rng(&ssl->ssl_conf, mbedtls_ctr_drbg_random, &ssl->ctr_drbg);
	mbedtls_ssl_conf_dbg(&ssl->ssl_conf, mytls_debug, NULL);
    if ((ret= mbedtls_ssl_setup(&ssl->ssl_ctx, &ssl->ssl_conf)) != 0) {
        DBG("mbedtls_ssl_setup() failed, value:-0x%x.", -ret);
        ret = -1;
        goto exit;
    }  
	mbedtls_ssl_set_bio(&ssl->ssl_ctx, &ssl->net_ctx, mbedtls_net_send, mbedtls_net_recv, mbedtls_net_recv_timeout);
    /*
    * Handshake
    */
    while ((ret = mbedtls_ssl_handshake(&ssl->ssl_ctx)) != 0) {
        if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) {      
            DBG("mbedtls_ssl_handshake() failed, ret:-0x%x.", -ret);
            ret = -1;
            goto exit;
        }
    }
    /*
     * Verify the server certificate
     */
    /* In real life, we would have used MBEDTLS_SSL_VERIFY_REQUIRED so that the
        * handshake would not succeed if the peer's cert is bad.  Even if we used
        * MBEDTLS_SSL_VERIFY_OPTIONAL, we would bail out here if ret != 0 */
    if ((flags = mbedtls_ssl_get_verify_result(&ssl->ssl_ctx)) != 0) {
        char vrfy_buf[512];
        DBG("svr_cert varification failed.");
        mbedtls_x509_crt_verify_info(vrfy_buf, sizeof(vrfy_buf), "  ! ", flags);
        DBG("%s", vrfy_buf);
    }
    else
        DBG("svr_cert varification ok.\r\n"); 
exit:	
    return ret;
}

int NetworkConnect(Network* n, char* addr, int port)
{
#ifdef USE_TLS
	return tls_tcp_connect(n, addr, port);
#else
	int type = SOCK_STREAM;
	struct sockaddr_in address;
	int rc = -1;
	sa_family_t family = AF_INET;
	struct addrinfo *result = NULL;
	struct addrinfo hints = {0, AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP, 0, NULL, NULL, NULL};

	if ((rc = getaddrinfo(addr, NULL, &hints, &result)) == 0)
	{
		struct addrinfo* res = result;

		/* prefer ip4 addresses */
		while (res)
		{
			if (res->ai_family == AF_INET)
			{
				result = res;
				break;
			}
			res = res->ai_next;
		}

		if (result->ai_family == AF_INET)
		{
			address.sin_port = htons(port);
			address.sin_family = family = AF_INET;
			address.sin_addr = ((struct sockaddr_in*)(result->ai_addr))->sin_addr;
		}
		else
			rc = -1;

		freeaddrinfo(result);
	}

	if (rc == 0)
	{
		n->my_socket = socket(family, type, 0);
		if (n->my_socket != -1)
			rc = connect(n->my_socket, (struct sockaddr*)&address, sizeof(address));
		else
			rc = -1;
	}

	return rc;
#endif
}

void NetworkDisconnect(Network* n)
{
#ifdef USE_TLS
	tls_t *ssl = n->tls;
    if (!ssl)
        return;
    
    mbedtls_ssl_close_notify(&ssl->ssl_ctx);
    mbedtls_net_free(&ssl->net_ctx);
    mbedtls_x509_crt_free(&ssl->cacert);
    mbedtls_x509_crt_free(&ssl->clicert);
    mbedtls_pk_free(&ssl->pkey);
    mbedtls_ssl_free(&ssl->ssl_ctx);    
    mbedtls_ssl_config_free(&ssl->ssl_conf);
    mbedtls_ctr_drbg_free(&ssl->ctr_drbg);
    mbedtls_entropy_free(&ssl->entropy);
    
    free(ssl);	
#else
	close(n->my_socket);
#endif
}
