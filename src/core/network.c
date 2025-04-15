/*

   Copyright (C) 2024 BIAGINI Nathan

   This software is provided 'as-is', without any express or implied
   warranty.  In no event will the authors be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
   3. This notice may not be removed or altered from any source distribution.

*/

#include <stdlib.h>
#include <limits.h>
#include "getopt.h"

// nbnet implementation
#define NBNET_IMPL 

#include "network.h"

// Command line options
enum
{
    OPT_MESSAGES_COUNT,
    OPT_PACKET_LOSS,
    OPT_PACKET_DUPLICATION,
    OPT_PING,
    OPT_JITTER
};

static Options options = {0};

// ChangePosMessage
ChangePosMessage *ChangePosMessage_Create(void)
{
    return malloc(sizeof(ChangePosMessage));
}

void ChangePosMessage_Destroy(ChangePosMessage *msg)
{
    free(msg);
}

int ChangePosMessage_Serialize(ChangePosMessage *msg, NBN_Stream *stream)
{
    NBN_SerializeFloat(stream, msg->x, BOARD_X, BOARD_X + BOARD_WIDTH, 3);
    NBN_SerializeFloat(stream, msg->y, BOARD_Y, BOARD_Y + BOARD_HEIGHT, 3);

    return 0;
}

TokenStatusMessage *TokenStatusMessage_Create(void)
{
    return malloc(sizeof(TokenStatusMessage));
}

void TokenStatusMessage_Destroy(TokenStatusMessage *msg)
{
    free(msg);
}

int TokenStatusMessage_Serialize(TokenStatusMessage *msg, NBN_Stream *stream)
{
    NBN_SerializeUInt(stream, msg->status, 0, MAX_TOKEN_STATUS);

    return 0;
}
GameStateMessage *GameStateMessage_Create(void)
{
    return malloc(sizeof(GameStateMessage));
}

void GameStateMessage_Destroy(GameStateMessage *msg)
{
    free(msg);
}

int GameStateMessage_Serialize(GameStateMessage *msg, NBN_Stream *stream)
{
    NBN_SerializeUInt(stream, msg->client_count, 0, MAX_CLIENTS);

    for (unsigned int i = 0; i < msg->client_count; i++)
    {
        NBN_SerializeUInt(stream, msg->client_states[i].client_id, 0, UINT_MAX);
        NBN_SerializeUInt(stream, msg->client_states[i].client_index, 0, MAX_CLIENTS);
        NBN_SerializeUInt(stream, msg->client_states[i].token_count, 0, MAX_TOKENS);
        for (unsigned int j = 0; j < msg->client_states[j].token_count; j++)
        {
            NBN_SerializeUInt(stream, msg->client_states[j].tokens[j].token_id, 0, UINT_MAX);
            NBN_SerializeUInt(stream, msg->client_states[i].tokens[j].status, 0, MAX_TOKEN_STATUS);
            NBN_SerializeFloat(stream, msg->client_states[j].tokens[j].x, BOARD_X, BOARD_X + BOARD_WIDTH, 3);
            NBN_SerializeFloat(stream, msg->client_states[j].tokens[j].y, BOARD_Y, BOARD_Y + BOARD_HEIGHT, 3);
        }
    }

    return 0;
}

// Parse the command line
int ReadCommandLine(int argc, char *argv[])
{
    int opt;
    int option_index;
    struct option long_options[] = {
        { "packet_loss", required_argument, NULL, OPT_PACKET_LOSS },
        { "packet_duplication", required_argument, NULL, OPT_PACKET_DUPLICATION },
        { "ping", required_argument, NULL, OPT_PING },
        { "jitter", required_argument, NULL, OPT_JITTER }
    };

    while ((opt = getopt_long(argc, argv, "", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
            case OPT_PACKET_LOSS:
                options.packet_loss = atof(optarg);
                break;

            case OPT_PACKET_DUPLICATION:
                options.packet_duplication = atof(optarg);
                break;

            case OPT_PING:
                options.ping = atof(optarg);
                break;

            case OPT_JITTER:
                options.jitter = atof(optarg);
                break;

            case '?':
                return -1;

            default:
                return -1;
        }
    }

    return 0;
}

// Return the command line options
Options GetOptions(void)
{
    return options;
}