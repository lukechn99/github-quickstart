### Gas
It takes gas (ETH) to run functions on DApps. Gas costs are increased based on complexity of function and storage needs.  

### Contracts and Interfaces
You can use existing contracts on the blockchain by declaring an Interface

### Immutability
Contracts on the blockchain cannot be changed once deployed, so you, the owner, should always build some backdoors to making key changes in the functionality. Think about the ways in which your DApp could break over time and try to build resiliency through backdoors. Typically, the backdoor will come in the form of ownership where you have the DApp recognize you as owner as soon as it's deployed and then have available some functions that are only owner accessible for you to use.  
