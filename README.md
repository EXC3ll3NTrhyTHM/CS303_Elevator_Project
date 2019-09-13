# Project 1C (Open Project)
• Choose some of the data structures we studied or make your own to simulate how an elevator
handles and keeps track of requests made by users.

• Here is how an elevator works: A user pushes either the up or down button to request the
elevator. Once the elevator arrives, the user gets in and specifies his/her destination floor.

Meanwhile, other users outside or inside the elevator make requests as well. The elevator
stores the requests and handles them efficiently.

• A simple algorithm for handling requests works like this: all requests users make are stored. The elevator prioritizes the requests that are on the way where it’s going, but also based on a first come first served principle. It is up to you how you design the algorithm. As a recommendation, observe how an elevator works (e.g. the elevator we have at FH) and simulate how it works.

### Technical Requirements
• (Weight: 60%) Write an efficient function that handles elevator requests. The function should result in a low waiting time for users. Make sure your function accommodates a single-elevator system and a multi-elevator system.

• (Weight: 40%) Write a simulation function that calculates the waiting time for users. Your
simulation algorithm could randomly generate users that come at random times and make
random requests. Alternatively, make your own scenarios and test the waiting time for those
scenarios. For inspiration, see how we simulated the airline passenger serving algorithm.

### Discussion
• Since this is an open project, the grading will largely depend on the thinking process and design decisions. Hence, you are welcome to discuss with me how you will approach the problem. 
