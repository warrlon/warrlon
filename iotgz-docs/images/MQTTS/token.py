import base64
import hmac
import time
from urllib.parse import quote

def token(id,access_key):

    version = '2018-10-31'

    res = 'products/%s' % id  # ͨ����ƷID���ʲ�ƷAPI

    # �û��Զ���token����ʱ��
    et = str(int(time.time()) + 3600)

    # ǩ��������֧��md5��sha1��sha256
    method = 'sha1'

    # ��access_key����decode
    key = base64.b64decode(access_key)

    # ����sign
    org = et + '\n' + method + '\n' + res + '\n' + version
    sign_b = hmac.new(key=key, msg=org.encode(), digestmod=method)
    sign = base64.b64encode(sign_b.digest()).decode()

    # value ���ֽ���url���룬method/res/versionֵ��Ϊ���������
    sign = quote(sign, safe='')
    res = quote(res, safe='')

    # token����ƴ��
    token = 'version=%s&res=%s&et=%s&method=%s&sign=%s' % (version, res, et, method, sign)

    return token


if __name__ == '__main__':
    id = '123123'
    access_key = 'KuF3NT/jUBJ62LNBB/A8XZA9CqS3Cu79B/ABmfA1UCw='
    
    print(token(id,access_key))