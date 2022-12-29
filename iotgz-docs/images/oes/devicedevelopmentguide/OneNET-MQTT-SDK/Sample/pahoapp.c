/*******************************************************************************
 * Copyright (c) 2012, 2016 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution. 
 *
 * The Eclipse Public License is available at 
 *   http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at 
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial contribution
 *    Ian Craggs - change delimiter option from char to string
 *    Al Stockdill-Mander - Version using the embedded C client
 *    Ian Craggs - update MQTTClient function names
 *******************************************************************************/

/*
 
 stdout subscriber
 
 compulsory parameters:
 
  cmdtopic to subscribe to
 
 defaulted parameters:
 
	--host localhost
	--port 1883
	--qos 2
	--delimiter \n
	--clientid stdout_subscriber
	
	--userid none
	--password none

 for example:

    stdoutsub cmdtopic/of/interest --host iot.eclipse.org

*/
#include <stdio.h>
#include <memory.h>
#include "../PahoMQTTSDK/MQTTClient.h"

#include <stdio.h>
#include <signal.h>

#include <sys/time.h>

#define STR_PAYLOAD "{\"datastreams\":[{\"id\":\"%s\",\"datapoints\":[{\"value\":%.2f}]}]}"
float value = 1.2;
volatile int toStop = 0;

char* cmdtopic  = "standard/cmd/pid/569/devkey/11326";
char* datatopic = "standard/data/pid/569/devkey/11326";
char* resptopic = "standard/resp/pid/569/devkey/11326";

struct opts_struct
{
	char* clientid;
	int nodelimiter;
	char* delimiter;
	enum QoS qos;
	char* username;
	char* password;
	char* host;
	int port;
	int showtopics;
} opts =
{
	(char*)"11326", 0, (char*)"\n", QOS0,(char*)"569", (char*)"NTZlNjEzMDI0YzA1N2JlNTkwYjU=", (char*)"10.12.4.25", 8896, 1
};


void usage()
{
	printf("MQTT stdout subscriber\n");
	printf("Usage: stdoutsub topicname <options>, where options are:\n");
	printf("  --host <hostname> (default is localhost)\n");
	printf("  --port <port> (default is 1883)\n");
	printf("  --qos <qos> (default is 2)\n");
	printf("  --delimiter <delim> (default is \\n)\n");
	printf("  --clientid <clientid> (default is hostname+timestamp)\n");
	printf("  --username none\n");
	printf("  --password none\n");
	printf("  --showtopics <on or off> (default is on if the cmdtopic has a wildcard, else off)\n");
	exit(-1);
}


void cfinish(int sig)
{
	signal(SIGINT, NULL);
	toStop = 1;
}

void getopts(int argc, char** argv)
{
	int count = 2;
	
	while (count < argc)
	{
		if (strcmp(argv[count], "--qos") == 0)
		{
			if (++count < argc)
			{
				if (strcmp(argv[count], "0") == 0)
					opts.qos = QOS0;
				else if (strcmp(argv[count], "1") == 0)
					opts.qos = QOS1;
				else if (strcmp(argv[count], "2") == 0)
					opts.qos = QOS2;
				else
					usage();
			}
			else
				usage();
		}
		else if (strcmp(argv[count], "--host") == 0)
		{
			if (++count < argc)
				opts.host = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--port") == 0)
		{
			if (++count < argc)
				opts.port = atoi(argv[count]);
			else
				usage();
		}
		else if (strcmp(argv[count], "--clientid") == 0)
		{
			if (++count < argc)
				opts.clientid = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--username") == 0)
		{
			if (++count < argc)
				opts.username = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--password") == 0)
		{
			if (++count < argc)
				opts.password = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--delimiter") == 0)
		{
			if (++count < argc)
				opts.delimiter = argv[count];
			else
				opts.nodelimiter = 1;
		}
		else if (strcmp(argv[count], "--showtopics") == 0)
		{
			if (++count < argc)
			{
				if (strcmp(argv[count], "on") == 0)
					opts.showtopics = 1;
				else if (strcmp(argv[count], "off") == 0)
					opts.showtopics = 0;
				else
					usage();
			}
			else
				usage();
		}
		count++;
	}
	
}


void messageArrived(MessageData* md)
{
	MQTTMessage* message = md->message;

	if (opts.showtopics)
		printf("%.*s\t", md->topicName->lenstring.len, md->topicName->lenstring.data);
	if (opts.nodelimiter)
		printf("%.*s", (int)message->payloadlen, (char*)message->payload);
	else
		printf("%.*s%s", (int)message->payloadlen, (char*)message->payload, opts.delimiter);
	//fflush(stdout);
}


int main(int argc, char** argv)
{
	int rc = 0;
	unsigned char buf[1000];
	unsigned char readbuf[1000];
	
	//if (argc < 2)
	//	usage();
	
	if (strchr(cmdtopic, '#') || strchr(cmdtopic, '+'))
		opts.showtopics = 1;
	if (opts.showtopics)
		printf("cmdtopic is %s\n", cmdtopic);

	//getopts(argc, argv);	

	Network n;
	MQTTClient c;

	signal(SIGINT, cfinish);
	signal(SIGTERM, cfinish);

	NetworkInit(&n);
	
	rc = NetworkConnect(&n, opts.host, opts.port);
	printf("NetworkConnect %d\n", rc);

	MQTTClientInit(&c, &n, 1000, buf, 1000, readbuf, 1000);
 
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;       
	data.willFlag = 0;
	data.MQTTVersion = 3;
	data.clientID.cstring = opts.clientid;
	data.username.cstring = opts.username;
	data.password.cstring = opts.password;

	data.keepAliveInterval = 10;
	data.cleansession = 1;
	printf("Connecting to %s %d\n", opts.host, opts.port);
	
	rc = MQTTConnect(&c, &data);
	printf("Connected %d\n", rc);
    
    printf("Subscribing to %s\n", cmdtopic);
	rc = MQTTSubscribe(&c, cmdtopic, opts.qos, messageArrived);
	printf("Subscribed %d\n", rc);

    int counter;
	while (!toStop)
	{
		value++;
		counter++;
		MQTTYield(&c, 1000);//后台接收数据处理函数
		if (counter%10==0){

			MQTTMessage message;

			char payload_in[2048] = { 0 };
			char* qtr_payload = payload_in + 3;
			sprintf(qtr_payload, STR_PAYLOAD, "test", value);
			payload_in[0] = 1;
			payload_in[1] = (strlen(qtr_payload) & 0xFF00) >> 8;
			payload_in[2] = strlen(qtr_payload);

			message.qos = QOS0;
			message.retained = 0;
			message.payload = payload_in;
			message.payloadlen = strlen(qtr_payload)+3;

			MQTTPublish(&c, datatopic, &message);
			printf("Return code from MQTT publish is %d\n", rc);
		}
	
	}
	
	printf("Stopping\n");

	MQTTDisconnect(&c);
	NetworkDisconnect(&n);

	return 0;
}


