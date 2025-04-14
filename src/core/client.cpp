// #define NBNET_IMPL
// #define NBN_Allocator malloc
// #define NBN_Reallocator realloc
// #define NBN_Deallocator free

// #include "client.h"
// #include "nbnet.h"
// #include "net_drivers/json.h"

// Client::Client(uint32_t client_id)
// {
//     // Update the local client state based on spawn info sent by the server
//     local_client_state.client_id = client_id;
// }

// void Client::spawnLocalClient() {
//     spawned = true;
// }

// void Client::handleConnection()
// {
//     uint8_t data[32];
//     unsigned int data_len = NBN_GameClient_ReadServerData(data);
//     NBN_ReadStream rs;

//     NBN_ReadStream_Init(&rs, data, data_len);

//     unsigned int x = 0;
//     unsigned int y = 0;
//     unsigned int client_id = 0;

//     NBN_SerializeUInt(((NBN_Stream *)&rs), x, 0, GAME_WIDTH);
//     NBN_SerializeUInt(((NBN_Stream *)&rs), y, 0, GAME_HEIGHT);
//     NBN_SerializeUInt(((NBN_Stream *)&rs), client_id, 0, UINT_MAX);

//     SpawnLocalClient();

//     connected = true;
// }