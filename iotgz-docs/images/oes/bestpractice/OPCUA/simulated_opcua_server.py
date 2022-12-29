#!/usr/bin/env python3

from opcua import ua, uamethod, Server
from threading import Thread
import logging
import random
import time
import sys
sys.path.insert(0, "..")


def switch_lamp(parent, variant):
    print("switch_lamp %d", variant.Value)
    temperature_thread.state.set_value(variant.Value)

def set_temperature(parent, variant):
    print("switch_lamp %d", variant.Value)
    temperature_thread.temperature.set_value(variant.Value)

def check_user(session,username,password):
    return username=="aaa" and bytes.decode(password)=="bbb"

class lamp_random(Thread):

    def __init__(self, temperature, state):
        Thread.__init__(self)
        self._stop = False
        self.temperature = temperature
        self.state = state

    def stop(self):
        self._stop = True

    def run(self):
        while not self._stop:
            value = random.randint(-30, 100)
            self.temperature.set_value(value)

            value = bool(random.randint(0, 1))
            self.state.set_value(value)

            time.sleep(5)

if __name__ == "__main__":

    # optional: setup logging
    logging.basicConfig(level=logging.WARN)

    # now setup server
    server = Server()
    server.set_endpoint("opc.tcp://0.0.0.0:4840/freeopcua/server/")
    server.set_server_name("FreeOpcUa Simulated Server")

    # set all possible endpoint policies for clients to connect through
    server.set_security_policy([
                ua.SecurityPolicyType.NoSecurity,
                ua.SecurityPolicyType.Basic128Rsa15_SignAndEncrypt,
                ua.SecurityPolicyType.Basic128Rsa15_Sign,
                ua.SecurityPolicyType.Basic256_SignAndEncrypt,
                ua.SecurityPolicyType.Basic256_Sign])
    
    #server.load_certificate("./cert.pem")
    #server.load_private_key("./key.pem")
    #server.user_manager.user_manager=lambda session,username,password:username=="aaa" and bytes.decode(password)=="bbb"
    server.user_manager.user_manager=check_user
	
    # setup namespace
    uri = "http://examples.freeopcua.github.io"
    idx = server.register_namespace(uri)
    
    # create directly some objects and variables
    lamp = server.nodes.objects.add_object(idx, "lamp")
    lamp_temp = lamp.add_variable(idx, "temperature", 20)
    lamp_temp.set_writable()
    lamp_state = lamp.add_variable(idx, "off", True)
    lamp_state.set_writable()
    lamp_switch = lamp.add_method(idx, "switch", switch_lamp, [ua.VariantType.Boolean])
    lamp_set_temp = lamp.add_method(idx, "set_temperature", set_temperature, [ua.VariantType.Int32])


    # start opcua server
    server.start()
    print("Start opcua server...")

    lamp_random_thread = lamp_random(lamp_temp, lamp_state)
    lamp_random_thread.start()

    while True:
        time.sleep(5)
	
    print("Exit opcua server...")
    lamp_random_thread.stop()
    server.stop()
