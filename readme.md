        __    __     ___  _____  ____  ____  _  _  ____   ____  ____ 
       /__\  (  )   / __)(  _  )( ___)(_  _)( \( )(  _ \ ( ___)(  _ \
      /(  )\  )(__ ( (_-. )(_)(  )__)  _)(_  )  (  )(_) ) )__)  )   /
     (__)(__)(____) \___/(_____)(_)   (____)(_)\_)(____/ (____)(_)\_)


# AlgoFinder

AlgoFinder is a simple project dedicated to showing how different algorithms relevant to Computer Science function in a visual manner. 


## Implementation Questions

What options do I want for each edge?
- Non-Directional [-]
- Directional [X]
  - Show arrows for directionality within the space [X]
- Show weights in Graph Space? [-]
  - Calculate angle for weight to display at? [-]



## Current Issues

Edge Removal
- May need to change underlying data structure, as edge IDs are changing when nodes are being removed
  - This interacts with the Adjacency list poorly... Maybe just change the adjacency list? O(n^2) algorithm...