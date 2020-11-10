# Signals
Signals are asynchronous IPC, it is a software interrupt typically used for unusual events  
They are usually sent from OS to process but can also be sent from process to process  
```kill -s <signal name> <pid>``` kill does not mean to kill, but to send the signal, if you want to kill, you can send ```kill -s SIGKILL 1234```  
For example, ^C sends a SIGINT to the process and stops it. The CPU is running the process, but will check for signals every now and then. The OS turns the hardware signal into a software signal, the OS sends a software interrupt
SIGABRT: process abort  
SIGINT: Ctrl+c
etc.
### Handling Signals
4 ways: default action, ignore, (un)block signals, take specific action/handle
