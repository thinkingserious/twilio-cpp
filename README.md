# Sending an SMS Message with C++ and Twilio on macOS

The following is a command that compiles the `send_sms.cpp` file using the g++ compiler and generates an executable file named `send_sms`. The `-o` option is used to specify the name of the output file, which is `send_sms` in this case. The `send_sms.cpp` argument specifies the source code file to be compiled.

The `-lcurl` option is used to link the `libcurl` library with the executable file. `libcurl` is a library that provides functions for sending and receiving data over HTTP and other protocols. The `send_sms.cpp` file uses the `libcurl` library to send an HTTP request to the Twilio API to send an SMS message.

The resulting executable file `send_sms` can be used to send an SMS message using the [Twilio API](https://www.twilio.com/try-twilio) by running it in the terminal.

```zsh
g++ -o send_sms send_sms.cpp -lcurl
```

Setup your environment variables: https://www.twilio.com/try-twilio

```zsh
cp .env.example .env
source .env
```

Send the SMS

```zsh
./send_sms
```
