#include "include/client.h"

#include <sys/socket.h>

#include <set>
#include <string>

#include <xdrpp/rpcbind.hh>
#include <xdrpp/socket.h>

#include <include/rpcconfig.h>
#include <include/server.hh>

using namespace std;
using namespace xdr;

Client::Client()
{
    client = NULL;
}

Client::~Client()
{
    this->close();
}

void
Client::open(const std::string &host)
{
    if (isConnected()) {
        cout << "Already connected!" << endl;
        exit(1);
    }

    auto fd = tcp_connect(host.c_str(), UNIQUE_RPC_PORT);
    client = new srpc_client<api_v1>{fd.release()};
}

void
Client::close()
{
    if (isConnected()) {
        delete client;
        client = NULL;
    }
}

bool
Client::isConnected()
{
    return client != NULL;
}

bool
Client::create(const std::string &path, const std::string &val)
{
    kvpair args;

    args.key = path;
    args.val = val;

    auto r = client->create(args);

    if (r->type() == ERROR) {
        throw ClientException(r->error());
    }

    return r->value();
}

bool
Client::remove(const std::string &path)
{
    auto r = client->remove(path);

    if (r->type() == ERROR) {
        throw ClientException(r->error());
    }

    return r->value();
}

std::string
Client::get(const std::string &path)
{
    auto r = client->get(path);

    if (r->type() == ERROR) {
        throw ClientException(r->error());
    }

    return r->value();
}

void
Client::set(const std::string &path, const std::string &val)
{
    kvpair args;

    args.key = path;
    args.val = val;

    auto r = client->set(args);

    if (r->type() == ERROR) {
        throw ClientException(r->error());
    }
}

std::set<string>
Client::list(const string &path)
{
    auto r = client->list(path);
    
    if (r->type() == ERROR) {
        throw ClientException(r->error());
    }
    
    return std::set<string>(r->value().begin(), r->value().end());
}

