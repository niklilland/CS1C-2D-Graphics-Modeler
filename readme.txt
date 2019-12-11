CS1C - Team Solaris

Application Requirements
------------------------

1. Provide satisfied customer testimonials (solicit for additional
testimonials). Guest users may enter testimonials. The testimonials
should be persistent between executions.  

2. Provide “contact us” method with team name and logo

3. Display all graphic objects (i.e. shapes including text) in rendering
window. The shape id will be displayed above each shape identifying
it. The rendering area to display shapes must have minimum
dimensions of 1000 pixels (horizontal) by 500 pixels (vertical). The
coordinate system is defined such that the top left corner of the
rendering area is located at point (0,0), the bottom right corner at
point (1000,500).

4. Your program should read from a shape file that keeps track of all
shapes currently being rendered by the 2D modeler. Shapes are
identified by their type: line, polyline, polygon, rectangle, ellipse,
text. Shapes have properties: shape dimensions, pen color, pen
width, pen style, pen cap style, pen join style, brush color, brush
shape. Text has properties: shape dimensions, text string, text
color, text alignment, text point size, text font family, text font
style, text font weight. All shapes must also have a unique ID.

5. Your program should be able to move shapes, including text, being
rendered. This is accomplished via a move shape form. All changes
are visible in the rendering area. – administrator only

6. Your program should be able to add and remove shapes, including
text, being rendered. This is accomplished via an add/remove shape
form. All changes are visible in the rendering area. – administrator
only

7. Produce a shape listing report sorted by shape id (at any time). All
shape properties should be included in the report.

8. Produce a shape listing report of ONLY shapes with an area sorted
by area (at any time). The shape type, id and area should be
included in the report.

9. Produce a shape listing report of ONLY shapes with a perimeter
sorted by perimeter (at any time). The shape type, id and perimeter
should be included in the report.

10. Save all changes between executions


Submission List
---------------

1) URL to GitHub repository.  

2) zip file containing complete Qt project.  To include working UI once 
project is opened and built in Qt.  

3) zip file containing ONLY the class files written specifically to 
satisfy project requirements.  These classes are included in the Qt front 
end UI project from step 2) 

4) text file documenting which source files, line numbers from step 3) 
satisfy individual project requirements (#1 thru #10) and general project 
requirements (second paragraph of assignment).  For each project 
requirement include source file .h, .cpp name and relevant line numbers. 

5) agile product backlog, scrum backlog for sprint #1, #2 and daily scrum 
meeting documentation 

6) zip file containing doxygen class documentation

7) hwgp01: at least 10 agile user stories
--- Previuously submitted - part of SCRUM docs in Scrum Directory

8) REMOVED - hwgp02: white box unit tests and test plan (hwgp02 
requirement has been removed, assignment not due) 

9) UML class diagram, at least three use cases and at least three 
state diagrams 

10) valgrind memory leak check

11) completed team project member contribution form.
