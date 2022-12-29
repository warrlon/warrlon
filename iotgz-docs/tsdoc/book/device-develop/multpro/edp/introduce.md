# Introduction to EDP

EDP (Enhanced Device Protocol Enhanced Device Protocol) is a fully open TCP-based protocol customized by OneNET platform according to the characteristics of the Internet of Things. It can be widely used in home, transportation, logistics, energy and other industries.

## Functional characteristics

- Long Connection Protocol
- Data Encryption Transmission
- The terminal data point report supports data point types as follows:
    - Floating Points
    - Integer (int)
    - String
    - JSON object
    - Binary data
- Platform messaging (support offline messaging)
- End-to-end data forwarding

## Typical application scenarios

EDP protocol is suitable for use scenarios where devices and platforms need to maintain long connection point-to-point control. Based on TCP protocol, this protocol only transmits data packets to the destination, and does not guarantee that the order of transmission is the same as the order of arrival. Transaction mechanism needs to be implemented at the upper level. If the client initiates two requests at the same time, the order of return message is not guaranteed when the server returns. EDP protocol is suitable for long connection reporting, transmission, forwarding, storage and active data downloading scenarios.

Taking precision agriculture as an example, terminal equipment can upload environmental data such as air temperature and humidity, illumination, soil temperature and humidity, pH value, nitrogen, phosphorus and potassium nutrition value in monitoring area through EDP protocol. OneNET can push data to user's application server. Users can use expert system to analyze these data, and control the light supplement lamp, fan and shade connected on equipment. Sunshade, drip irrigation and other facilities can achieve automatic and intelligent regulation and control, so that the crop growth environment is always in the best state, in order to achieve the goal of high efficiency and high yield.