
// class Client
// {
// public:
//     Client(uint32_t client_id);
//     void spawnLocalClient();
//     void handleConnection();
//     {
//         // Update the local client state based on spawn info sent by the server
//         local_client_state.client_id = client_id;
//         spawned = true;
//     }

// private:
//     static bool connected = false;         // Connected to the server
//     static bool disconnected = false;      // Got disconnected from the server
//     static bool spawned = false;           // Has spawned
//     static int server_close_code;          // The server code used when closing the connection
//     static ClientState local_client_state; // The state of the local client// Array to hold other client states (`MAX_CLIENTS - 1` because we don't need to store the state of the local client)
//     static ClientState *clients[MAX_CLIENTS - 1] = {NULL};
//     /*
//      * Array of client ids that were updated in the last received GameStateMessage.
//      * This is used to detect and destroy disconnected remote clients.
//      */
//     static int updated_ids[MAX_CLIENTS];
// }