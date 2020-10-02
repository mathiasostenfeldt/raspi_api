#ifndef API_LIGHTS_H
#define API_LIGHTS_H

//string* getAllRoomsWithLight(NetworkInterface* network);
void turnOnAllLight(NetworkInterface* network);
void turnOffAllLight(NetworkInterface* network);
void turnOnInRoom(NetworkInterface* network, int roomId);
void turnOffInRoom(NetworkInterface* network, int roomId);
//void dimmlight(NetworkInterface* network);

#endif