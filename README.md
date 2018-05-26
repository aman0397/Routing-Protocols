#Routing Protocols
> Routing in computer networks is used to route packets from one node to another. This function is performed in the network layer of the Netwrok architechture.
> Two of the most important routing protocols are:
* Link State Routing
* Distance Vector Routing

##Link State Routing
> Link State Routing replaced the Distance Vector Routing Protocol while the latter was being used in ARPANET until 1979. The primary shortcoming of Distance Vector reouting was the count to infinity problem which occured whenever the network topology changed.
> The idea behind Link State Routing is as follows:
l. Discover its neighbors and learn their network addresses.
l. Set the distance or cost metric to each of its neighbors.
l. Construct a packet telling all it has just learned.
l. Send the packet to and receive packets from all other routers.
l. Compute the shortest path to every other router.

> The primary implementation of the link state routing is based on the Dijkstra's algorithm. In the implementation, the libgraph library has been used to illustrate the exchange of packets across nodes in a network.  
