# Motion-Planning-Prashikshan

# Task 5

## Aim of the Task -
When we do a maze solving or complex line following, we need to count the number of nodes. A node is defined as a region over which all the IR sensors give reading 0 i.e. a node is a black surface and if it is a node, all the sensors lie on black surface. 

If we ask you to count the number of nodes encountered, most of you will say
if( all sensors are on black) 
{
count++;
}
But there is a problem. When we do so instead of incrementing by 1, the counter is incremented by large numbers when all the sensors are present in a particular node. Like the readings would be absurd, even if you have crossed one node your counter would show values like 56…34…98…15..or,any random values.
This happens because when the bot crosses the node, it stays on the black surface for few milliseconds, and according to the if( ) statement,as long as the if() statement is satisfied i.e. the bot is on the node(even if it's few milliseconds)  the counter goes on incrementing.

Go through the different resources on Internet, Google, YouTube, or any other source or website you feel authentic. 

