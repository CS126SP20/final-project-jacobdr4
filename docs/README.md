# Documentation for my final project

This is the documentation for my final project

#4/20/20
1. Sucessfully imported the cinderblock CoC-Button

#4/23/20
1. Imported the cinderblock CoC-Core
2. Added the SetUpButtons() and SetCoordinates() methods for the buttons
3. Imports are unfortunately not working yet

#4/24/20
1. Changed the cinderblock to Cinder-UI after CoC-Button/CoC-Core were not working
2. Created four buttons that are displayed on the UI. These are for selecting each drawing tool
3. Added CreateButton() Class that displays the buttons 

#4/26/20
1. Created the paintcanvas class with methods

#4/27/20
1. Added built in cinder methods for mouse control, including MouseDown(), MouseUp(), 
MouseMove(), and MouseDrag(). Also made instance variables to keep track of the location
of where the mouse was first pressed and the current location of the mouse.
2. Implemented the DrawLine() and DrawRect() methods that allows the user to draw
straight lines and rectangles, respectively. Used the cinder drawLine and drawStrokedRect
methods.
3. Implemented the DrawScribble() method so the user can freely draw on the screen. Used
the cinder shape2d class.
4. Added a Multislider UI element so the user can change the marker color
5. Changed the buttons to a radio so only one tool can be selected at a time. Still need
to implement the methods to change the tool based on the radio selection.
6. Changed the name of PaintCanvas to BoardUtils, since it better describes what the class
does
7. Created an Enum class of tools in boardutils.cpp, to easily select one
