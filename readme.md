
            d8b                      ,d8888b  d8,                d8b                 
            88P                      88P'    `8P                 88P                 
            d88                    d888888P                      d88                  
  d888b8b  888   d888b8b   d8888b   ?88'      88b  88bd88b  d888888   d8888b  88bd88b
  d8P' ?88  ?88  d8P' ?88  d8P' ?88  88P       88P  88P' ?8bd8P' ?88  d8b_,dP  88P'  `
  88b  ,88b  88b 88b  ,88b 88b  d88 d88       d88  d88   88P88b  ,88b 88b     d88     
  `?88P'`88b  88b`?88P'`88b`?8888P'd88'      d88' d88'   88b`?88P'`88b`?888P'd88'     
                        )88                                                           
                      ,88P                                                           
                  `?8888P                                                            



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