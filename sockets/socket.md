# Socket Tutorial

## Basics
Sockets are an endpoint of communication to which a name may be bound. Each socket in use has a type and one or more associated processes. Sockets exist withint communication domains. A communication domain is an abstraction introduced to bundle common properties of processes communication through sockets.

### 1) Socket Types
Sockets are *typed* according to the communication properties visible to a user. *Processes* are presumed to communicate only between sockets of the same type.

Types of sockets:
* Stream socket (TCP):
	- Provides for the **bidirectional, reliable, sequenced, and unduplicated** flow of data without record boundaries.
	- A pair of connected stream sockets provides an interface nearly identical to that of pipes.
* Datagram socket (UDP):
	- Supports **bidirectional** flow of data that **isn't** guaranteed to be **sequenced, reliable, or unduplicated**.
	- A process receiving messages on a datagram socket may find messages duplicated, order other than sent.
* Raw socket (UDP-like):
	- Communication protocol that supports socket abstraction.
	- Normally datagram-oriented though the characteristics depend on the interface provided by the protocol.
	- Used for developing new communication protocols or gaining access to some of the more esoteric facilites of an existing protocol.

### 2) Creating Sockets
* `socket( domain, type, protocl)`:
	- Requests that a socket be created in the specified *domain* and *type*. *Protocl* may be unspecified (value of zero (0)), then the system will select an appropriate protocol from those protocols thank make up the communication domain and that can be used to support the requested socket type. A socket descriptor is returned that may be used in later functions that operate on sockets.

* Domain:
	- Specified in the file `<sys/socket.h>`
	- Constant AF_INET
* Type:
	- Specified in the file `<sys/socket.h>`
	- Constant SOCK_STREAM (TCP), SOCK_DGRAM (UDP), or SOCK_RAW (UDP-like)

**FIGURE 2.1**
```c
#include <sys/socket.h>
...
sd = socket(AF_INET, SOCK_STREAM, 0);
```

Figure 2.1 would result in a stream socket being created with the TCP protocol providing the underlying communication support. `sd` is the socket descriptor returned by `socket()`.

A socket call may fail for any of following reason:
* **ENOBUFS**:
  - Lack of memory
* **EPROTONOSUPPORT**:
  - Requests for an unknown protocol
* **EPROTOTYPE**:
  - Requests for a type of socket for which there's no supporting protocol

### 3) Binding Local Names
Until a *name* is bounded to a socket, processes have no way to reference it and no messages may be received on it. Communication processes are bound by an "association".

Association are composed of local and remote address, and local and remote ports. These associations must be unique, never duplicated.

* `bind( sd, name, namelen )`:
	- The bound name is a variable-length byte string that's interpreted by the supporting protocols. Internet domain contain an Internet address and port number.
	- The `bind()` function allows a process to specify half of an association (local address and port)
	- The `connect()` and/or `accept()` function are used to complete a socket's assocation.

**FIGURE 3.1**
```c
#include <sys/types.h>
#include <netinet/in.h>
...
struct sockaddr_in sin;
...
bind( sd, (struct sockaddr *) &sin, sizeof(sin) );
```

Figure 3.1 would bind the address in `sin` to `sd`. Deciding what should be placed in the address requires futher discussion.

### 4) Establishing Connections
Establishing a connection is usually asynmetric
* One process is a client
* Other process is a server

The server binds a socket to a well-known address associated with the service and then passively listens on its socket.
* The server binds the client using `connect()` and/or `accept()`.
* In this case, we're using `connect()`.
* See section 6 for `accept()`.

**FIGURE 4.1**
```c
// Same inclusions as Figure 2.1 and 3.1
...
struct sockaddr_in server;
...
connect( sd, (struct sockaddr *) &server, sizeof(server) );
```

Figure 4.1, `server` contains the internet adress and port number that the client wishes to speak to. If the client's socket is unbound at the time of the connect call, the system will automatically select and bind a name to the socket if necessary.

Several errors could occur while establishing a connection:
* **ETIMEDOUT**:
	- After failing to establish a connection for a period of time, the system decided there was no point in retrying
	- Destination host is down or because problems in the network resulted in the loss of transmission
* **ECONNREFUSED**:
	- The host refused service for some reason
	- Usually because a server process isn't being presented the request name.
* **ENETDOWN** or **EHOSTDOWN**:
	- The operational errors are returned based on status information delivered to the client host by the underlying communication services.
* **ENERUNREACH** or **EHOSTUNREACH**:
	- Network or host is unknown (no route to the network or host is present)
	- Status information returned by intermediate gateways
	- Switching nodes

### 5) Listening on a Socket
For the server to receive a client's connection (aftering binding its socket):
* Indicate a willingness to listen for incoming connection requests
* Actually accept the connection (Section 6)

`listen( sd, 5 )`:
* To listen for connections requests
* Server is listening on `sd` (server descriptor)
* The `5` parameter specifies the maximum number of outstanding connections that may be queued awaiting acceptance by the server process
	- This is called the *backlog*
	- There is a system-defined number of maximum connections on any one queue
	- Prevents processes from hogging system resources

If the *backlog* is full, the server will ignore the message and force the client to retry. While the client retries, the server has time to make room in its pending connection queue.
By having the server ignore the connection request, this will make it possible to get the **ETIMEDOUT** error.

### 6) Accepting a Connection
With a socket marked as listening, a server may accept a connection

**FIGURE 6.1**
```c
// Same inclusions as Figure 2.1 and 3.1
...
struct sockaddr_in client;
...
client_len = sizeof(client);
int new_sd = accept( sd, (struct sockaddr *) &client, &client_len );
```

Figure 6.1 accpets a connection and a new descriptor is returned (`new_sd`) along with the new socket (`client`).

Identify the client socket's name:
* Supply buffer for the client socket's name.
* The value-result parameter `client_len` is initialized by the server to indicate how much space is associated with `client`, and is then modified on return to reflect the true size of the name.

`accept()` is a blocking call, it won't return until a connection is available or until the call is interrupted by a signal to the process.
