# Minitalk

Minitalk is a 42 project that involves creating a simple client-server communication program using UNIX signals.

## Description

The goal of this project is to implement a **client-server** program where the client sends a string to the server, and the server prints it using only **UNIX signals** (`SIGUSR1` and `SIGUSR2`).

## Features

- Supports sending messages from client to server.
- Handles Unicode characters.
- Server prints received messages and confirms reception.
- Efficient signal handling.
- Bonus: Handles multiple clients and supports additional features.

## Installation

```sh
# Clone the repository
git clone https://github.com/aylaaouf/minitalk.git
cd minitalk

# Compile the project
make
```

## Usage

### Start the server

```sh
./server
```

The server will display its **PID** (Process ID), which is needed for the client to send messages.

### Send a message from the client

```sh
./client <server_pid> "Your message here"
```

Example:

```sh
./client 12345 "Hello, world!"
```

## Signals Used

- **SIGUSR1** (`10`): Used to send a `1` bit.
- **SIGUSR2** (`12`): Used to send a `0` bit.
- The client encodes each character as a series of bits and transmits them using these signals.

## Bonus Features

- Handles Unicode characters properly.
- Supports multiple clients simultaneously.
- Prints acknowledgment message when receiving a string.
- Enhanced error handling.

---

Made with ❤️ by [aylaaouf](https://github.com/aylaaouf)
