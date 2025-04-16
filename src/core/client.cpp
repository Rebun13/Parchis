// #define NBNET_IMPL
// #define NBN_Allocator malloc
// #define NBN_Reallocator realloc
// #define NBN_Deallocator free

// #include "client.h"
// #include "nbnet.h"
// #include "net_drivers/json.h"
// #include <stdexcept>

// Client::Client(uint32_t client_id)
// {
//     connected = false;
//     disconnected = false;
//     spawned = false;
//     // Update the local client state based on spawn info sent by the server
//     local_client_state.client_id = client_id;
//     client_count = 0;
// }

// Client::~Client()
// {
//     NBN_GameClient_Stop();
// }

// void Client::spawnLocalClient(
//     uint32_t client_id,
//     unsigned char client_index,
//     unsigned char token_count,
//     TokenState *tokens)
// {
//     local_client_state.client_id = client_id;
//     local_client_state.client_index = client_index;
//     local_client_state.token_count = token_count;
//     local_client_state.tokens = tokens;

//     spawned = true;
// }

// void Client::handleConnection()
// {
//     uint8_t data[32];
//     unsigned int data_len = NBN_GameClient_ReadServerData(data);
//     NBN_ReadStream rs;

//     NBN_ReadStream_Init(&rs, data, data_len);

//     uint32_t client_id = 0;
//     unsigned char client_index = 0;
//     const unsigned char token_count = 4;

//     uint32_t token_id = 0;
//     TokenStatus status = TokenStatus::STATIC;
//     float x = -1000.f;
//     float y = -1000.f;
//     TokenState tokens[token_count];

//     NBN_SerializeUInt(((NBN_Stream *)&rs), client_id, 0, UINT_MAX);
//     NBN_SerializeUInt(((NBN_Stream *)&rs), client_index, 0, MAX_CLIENTS);
//     NBN_SerializeUInt(((NBN_Stream *)&rs), token_count, 0, MAX_TOKENS);
//     for (unsigned int j = 0; j < token_count; j++)
//     {
//         tokens[j] = {client_id, token_id, x, y, status};
//         NBN_SerializeUInt(((NBN_Stream *)&rs), token_id, 0, UINT_MAX);
//         NBN_SerializeFloat(((NBN_Stream *)&rs), x, BOARD_X, BOARD_X + BOARD_WIDTH, 3);
//         NBN_SerializeFloat(((NBN_Stream *)&rs), y, BOARD_Y, BOARD_Y + BOARD_HEIGHT, 3);
//         NBN_SerializeUInt(((NBN_Stream *)&rs), status, 0, MAX_TOKEN_STATUS);
//     }

//     spawnLocalClient(client_id, client_index, token_count, tokens);

//     connected = true;
// }

// void Client::handleDisconnection()
// {
//     int code = NBN_GameClient_GetServerCloseCode(); // Get the server code used when closing the client connection

//     TraceLog(LOG_INFO, "Disconnected from server (code: %d)", code);

//     disconnected = true;
//     server_close_code = code;
// }

// bool Client::clientExists(uint32_t client_id)
// {
//     for (int i = 0; i < MAX_CLIENTS - 1; i++)
//     {
//         if (clients[i] && clients[i]->client_id == client_id)
//             return true;
//     }

//     return false;
// }

// void Client::createClient(ClientState state)
// {
//     TraceLog(LOG_DEBUG, "CreateClient %d", state.client_id);
//     assert(client_count < MAX_CLIENTS - 1);

//     ClientState *client = NULL;

//     // Create a new remote client state and store it in the remote clients array at the first free slot found
//     for (int i = 0; i < MAX_CLIENTS - 1; i++)
//     {
//         if (clients[i] == NULL)
//         {
//             client = (ClientState *)malloc(sizeof(ClientState));
//             clients[i] = client;

//             break;
//         }
//     }

//     assert(client != NULL);

//     // Fill the newly created client state with client state info received from the server
//     memcpy(client, &state, sizeof(ClientState));

//     client_count++;

//     TraceLog(LOG_INFO, "New remote client (ID: %d)", client->client_id);
// }

// void Client::updateClient(ClientState state)
// {
//     ClientState *client = NULL;

//     // Find the client matching the client id of the received remote client state
//     for (int i = 0; i < MAX_CLIENTS - 1; i++)
//     {
//         if (clients[i] && clients[i]->client_id == state.client_id)
//         {
//             client = clients[i];

//             break;
//         }
//     }

//     assert(client != NULL);

//     // Update the client state with the latest client state info received from the server
//     memcpy(client, &state, sizeof(ClientState));
// }

// void Client::destroyClient(uint32_t client_id)
// {
//     // Find the client matching the client id and destroy it
//     for (int i = 0; i < MAX_CLIENTS - 1; i++)
//     {
//         ClientState *client = clients[i];

//         if (client && client->client_id == client_id)
//         {
//             TraceLog(LOG_INFO, "Destroy disconnected client (ID: %d)", client->client_id);

//             free(client);
//             clients[i] = NULL;
//             client_count--;

//             return;
//         }
//     }
// }

// void Client::destroyDisconnectedClients()
// {
//     /* Loop over all remote client states and remove the one that have not
//      * been updated with the last received game state.
//      * This is how we detect disconnected clients.
//      */
//     for (int i = 0; i < MAX_CLIENTS - 1; i++)
//     {
//         if (clients[i] == NULL)
//             continue;

//         uint32_t client_id = clients[i]->client_id;
//         disconnected = true;

//         for (int j = 0; j < MAX_CLIENTS; j++)
//         {
//             if ((int)client_id == updated_ids[j])
//             {
//                 disconnected = false;

//                 break;
//             }
//         }

//         if (disconnected)
//             destroyClient(client_id);
//     }
// }

// void Client::handleGameStateMessage(GameStateMessage *msg)
// {
//     if (!spawned)
//         return;

//     // Start by resetting the updated client ids array
//     for (int i = 0; i < MAX_CLIENTS; i++)
//         updated_ids[i] = -1;

//     // Loop over the received client states
//     for (unsigned int i = 0; i < msg->client_count; i++)
//     {
//         ClientState state = msg->client_states[i];

//         // Ignore the state of the local client
//         if (state.client_id != local_client_state.client_id)
//         {
//             // If the client already exists we update it with the latest received state
//             if (clientExists(state.client_id))
//                 updateClient(state);
//             else // If the client does not exist, we create it
//                 createClient(state);

//             updated_ids[i] = state.client_id;
//         }
//     }

//     // Destroy disconnected clients
//     destroyDisconnectedClients();

//     GameStateMessage_Destroy(msg);
// }

// void Client::handleReceivedMessage()
// {
//     // Fetch info about the last received message
//     NBN_MessageInfo msg_info = NBN_GameClient_GetMessageInfo();

//     switch (msg_info.type)
//     {
//     // We received the latest game state from the server
//     case GAME_STATE_MESSAGE:
//         handleGameStateMessage((GameStateMessage *)msg_info.data);
//         break;
//     }
// }

// void Client::handleGameClientEvent(int ev)
// {
//     switch (ev)
//     {
//     case NBN_CONNECTED:
//         // We are connected to the server
//         handleConnection();
//         break;

//     case NBN_DISCONNECTED:
//         // The server has closed our connection
//         handleDisconnection();
//         break;

//     case NBN_MESSAGE_RECEIVED:
//         // We received a message from the server
//         handleReceivedMessage();
//         break;
//     }
// }

// int Client::sendPositionUpdate(uint32_t token_id)
// {
//     UpdatePosMessage *msg = UpdatePosMessage_Create();

//     for (unsigned int i = 0; i < local_client_state.token_count; i++)
//     {
//         if (local_client_state.tokens[i].token_id == token_id)
//         {
//             msg->client_id = local_client_state.client_id;
//             msg->token_id = local_client_state.tokens[i].token_id;
//             msg->x = local_client_state.tokens[i].x;
//             msg->y = local_client_state.tokens[i].y;
//             break;
//         }
//     }

//     // Unreliably send it to the server
//     if (NBN_GameClient_SendUnreliableMessage(UPDATE_POS_MESSAGE, msg) < 0)
//         return -1;

//     return 0;
// }

// int Client::sendTokenStatusUpdate(uint32_t token_id)
// {
//     TokenStatusMessage *msg = TokenStatusMessage_Create();

//     // Fill message data
//     for (unsigned int i = 0; i < local_client_state.token_count; i++)
//     {
//         if (local_client_state.tokens[i].token_id == token_id)
//         {
//             msg->client_id = local_client_state.client_id;
//             msg->token_id = local_client_state.tokens[i].token_id;
//             msg->status = local_client_state.tokens[i].status;
//             break;
//         }
//     }

//     // Reliably send it to the server
//     if (NBN_GameClient_SendReliableMessage(UPDATE_STATUS_MESSAGE, msg) < 0)
//         return -1;

//     return 0;
// }

// int Client::update(void)
// {
//     if (!spawned)
//         return 0;

//     for (unsigned int i = 0; i < local_client_state.token_count; i++)
//     {
//         // Update token status
//         if (sendTokenStatusUpdate(local_client_state.tokens[i].token_id) < 0)
//         {
//             TraceLog(LOG_WARNING, "Failed to send color update");
//             return -1;
//         }

//         // Send the latest local client state to the server
//         if (sendPositionUpdate(local_client_state.tokens[i].token_id) < 0)
//         {
//             TraceLog(LOG_WARNING, "Failed to send client state update");
//             return -1;
//         }
//     }
//     return 0;
// }

// void Client::drawDebugInfo()
// {
//     NBN_ConnectionStats stats = NBN_GameClient_GetStats();
//     unsigned int ping = stats.ping * 1000;
//     unsigned int packet_loss = stats.packet_loss * 100;

//     DrawText(TextFormat("FPS: %d", GetFPS()), 450, 350, 32, MAROON);
//     DrawText(TextFormat("Ping: %d ms", ping), 450, 400, 32, MAROON);
//     DrawText(TextFormat("Packet loss: %d %%", packet_loss), 450, 450, 32, MAROON);
//     DrawText(TextFormat("Upload: %.1f Bps", stats.upload_bandwidth), 450, 500, 32, MAROON);
//     DrawText(TextFormat("Download: %.1f Bps", stats.download_bandwidth), 450, 550, 32, MAROON);
// }

// int Client::init()
// {
//     if (NBN_GameClient_StartEx(PARCHIX_PROTOCOL_NAME, "127.0.0.1", PARCHIX_PORT, NULL, 0) < 0)
//     {
//         TraceLog(LOG_WARNING, "Game client failed to start. Exit");
//         throw std::runtime_error("Game client failed to start. Exit");
//     }
//     // Register messages, have to be done after NBN_GameClient_StartEx
//     // Messages need to be registered on both client and server side
//     NBN_GameClient_RegisterMessage(
//         UPDATE_POS_MESSAGE,
//         (NBN_MessageBuilder)UpdatePosMessage_Create,
//         (NBN_MessageDestructor)UpdatePosMessage_Destroy,
//         (NBN_MessageSerializer)UpdatePosMessage_Serialize);
//     NBN_GameClient_RegisterMessage(
//         UPDATE_STATUS_MESSAGE,
//         (NBN_MessageBuilder)TokenStatusMessage_Create,
//         (NBN_MessageDestructor)TokenStatusMessage_Destroy,
//         (NBN_MessageSerializer)TokenStatusMessage_Serialize);
//     NBN_GameClient_RegisterMessage(
//         GAME_STATE_MESSAGE,
//         (NBN_MessageBuilder)GameStateMessage_Create,
//         (NBN_MessageDestructor)GameStateMessage_Destroy,
//         (NBN_MessageSerializer)GameStateMessage_Serialize);

//     // Network conditions simulated variables (read from the command line, default is always 0)
//     NBN_GameClient_SetPing(GetOptions().ping);
//     NBN_GameClient_SetJitter(GetOptions().jitter);
//     NBN_GameClient_SetPacketLoss(GetOptions().packet_loss);
//     NBN_GameClient_SetPacketDuplication(GetOptions().packet_duplication);
// }