#include "network.h"

#define TARGET_FPS 60

class Client
{
public:
    Client(uint32_t client_id);
    void spawnLocalClient(
        uint32_t client_id,
        unsigned char client_index,
        unsigned char token_count,
        TokenState *tokens);
    void handleConnection();
    void handleDisconnection();
    bool clientExists(uint32_t client_id);
    void createClient(ClientState state);
    void updateClient(ClientState state);
    void destroyClient(uint32_t client_id);
    void destroyDisconnectedClients();
    void handleGameStateMessage(GameStateMessage *msg);
    void handleReceivedMessage();
    void handleGameClientEvent(int ev);
    int sendPositionUpdate();
    int SendColorUpdate();
    int Update();
    double tick_dt();
    double acc();

private:
    bool connected;                 // Connected to the server
    bool disconnected;              // Got disconnected from the server
    bool spawned;                   // Has spawned
    int server_close_code;          // The server code used when closing the connection
    ClientState local_client_state; // The state of the local client// Array to hold other client states (`MAX_CLIENTS - 1` because we don't need to store the state of the local client)
    ClientState *clients[MAX_CLIENTS - 1] = {NULL};
    /*
     * Array of client ids that were updated in the last received GameStateMessage.
     * This is used to detect and destroy disconnected remote clients.
     */
    int updated_ids[MAX_CLIENTS];
    // Number of currently connected clients
    unsigned int client_count;
}