# Project Description and Overview
Incorporate 3D maps, physics, logistics, route planning, malfunctions, security, congestion, and cost.  
Iteration 2 - Development: In the development phase, we build the actual system to
make it work and be useful.
### Project Timeline:
11/9/2020 First Deliverable: Peer Reviews Provide feedback for your teammates on their iteration 1 design document.  
11/17/2020 & 11/19/2020 Automated Assessment We will run our extended tests once on each codebase. This will help you fix any issues you might have with our grading scripts.  
11/20/2020 Canvas / GitHub Final Deliverable: Iteration 2 All remaining business requirements. This includes the design document.  

# Background
### 2.1 The Planet X Drone Fleet
We have different types of drones to build the best delivery system based on their constraints, strengths, and weaknesses. In other words we are no longer working with simple drones.  
Specs: ```repo/project/data/planet-x.csv```  
  
### 2.2 Map Data
We will use real roadway data from OpenStreetMap (OSM), we retrieve info from OSM files in XML format taking into account elevation by retrieving a gtiff image from the
OpenTopography API as the Shuttle Radar Topography Mission (SRTM) data. We then use a custom python script to smoothly interpolate between the height data points, converting the data into a grid of comma separated float values (CSV file). We have access to a class-provided parser that takes in an OSM file retrieved from the OpenStreetMap application and a height map file stored as a CSV (comma separated value) file. To convert the raw data files
into a graph of nodes and edges, you can use the following code:  
```
entity_project::OSMGraphParser parser;
const entity_project::IGraph* graph = parser.CreateGraph("data/umn.osm",
"data/umn-height.csv");
```
These files are needed for parsing the UMN data into a graph and are located at the following locations:  
OSM File: repo/project/data/umn.osm  
Height File: repo/project/data/umn-height.csv  

### 2.3 Algorithms, aka Dijkstra's or A*
Dijkstra’s algorithm finds the shortest path between two points efficiently: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/  
References: https://www.youtube.com/watch?v=pVfj6mxhdMw and https://www.youtube.com/watch?v=GazC3A4OQTE  

# ANVIL Simulation Specification
All work is done in the team repo, feedback comes from ```devel``` branch and assessments from the ```release``` branch.  
CREATE A WORKING SOLUTION: Multiple drones should be delivering different sized packages at different speeds. Finally, the visual and other observers should be notified of package delivery events.  
We need to have **ALL PRIORITIES** and **1 or 2** additional features and **regression, unit, and integration** tests and **bug fixes**  

### Changes
Updated the Entity class - Uses a vector<float> instead of a float* for position and direction to prevent the buffer overflow problem.  
Updated the DroneDeliverySystem abstract class - Added a SetGraph(...) method for graph traversal.  
Added methods to the Package and Drone classes - These methods allow us to get additional details about drone delivery (movement, capacity, etc…)  
Created an IGraph interface (Includes IGraphNode) - These are used to describe the road map for the system.  
Created an OpenStreetViewGraphParser class - This class allows us to parse the raw osm and height data into an IGraph class, which can then be added to DroneDeliverySystem.  
EntityConsoleLogger - This is a new observer that prints the JSON values to the console screen when the OnEvent(...) method is called from a subject.  

### 3.1.2 Design Requirements
Team: build doxygen and UML  
Individual: review two team members to suggest improvements to the writing and other comments, review based on the iteration 1 Design Document Rubric, to be uploaded on canvas and emailed to members  
Revise and update your iteration 1 Design Document, add 3 paragraphs about a priority or feature you implemented, one that a teammate implemented, discuss design tradeoffs.  

### 3.2 Development Requirements
[Updated Support Code Docs](https://pages.github.umn.edu/umn-csci-3081-f20/project-portal/docs/html/)  
[Support Code Headers](https://pages.github.umn.edu/umn-csci-3081-f20/project-portal/docs/html/files.html)  
[Project Portal Wiki](https://github.umn.edu/umn-csci-3081-f20/project-portal/wiki)  
You need to do **20 points** of work  
  
### Priorities
Observer: clients can be notified of package delivery. ```AddObserver()``` when you create a package to monitor states scheduled, in route, delivered. Implement the package as the "subject" using the WebSceneViewer and EntityConsoleLogger. Events are reported with ```OnEvent()```. Events are reported on the event log. Packages can have many observers. They can be removed with ```removeObserver```. ***What happens when an observer is removed? Is it destroyed?***  
Dynamic Routing: Use the shortest path on a graph for package delivery. Replace ```SimpleUMNRouteManager``` with ```DroneDeliverySystem::SetGraph(...)```. Include end points and calculate using Euclidean distance.  
Drone Pool: Use a diverse set of drones to deliver packages. Using the CSV, cache results in a datastructure for use. Pay attention to the many new attributes of a drone.  

### Features
Drone Observer: notifies of drone path changes, informs the console log when a drone enters idle, moving.  
Drone Delivery Functionality: limitations of battery, carrying capacity, max speed, etc. ***Should be last to implement, would complicate others***  
Schedule Delivery Functionality:  
Drone Physics: Velocity, acceleration, force  

