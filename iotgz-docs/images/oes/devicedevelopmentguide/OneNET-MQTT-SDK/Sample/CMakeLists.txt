add_executable(
  pahoapp
  pahoapp.c
)
target_link_libraries(pahoapp paho-mqtt-sdk)

add_executable(
  onenestandardapp
  onenestandardapp.c
)
target_link_libraries(onenestandardapp onenet-mqtt-sdk paho-mqtt-sdk pthread m)
