Erick Alanis

Compilation:

    Compile by executing 'make final'

    Run by executing './final'


Controls:

    Press 'esc' to close the program

    Press '+' to increase FOV

    Press '-' to decrease FOV

    Alternatively, scroll up or down to increase and decrease FOV respectively

    Press 'x' or 'X' to toggle debug mode (shows boundary boxes for each object)

    Press '0' to reset the camera angle (this can help fix any glitch the camera may have)

    Arrow keys - navigation

    Press the 'middle mouse button' to rotate camera (alternative to arrow keys)

    Press 'right click' to pan the camera around (a little glitchy, working on fixing it)

    Press 'left click' to select an object (will be highlighted green when selected)
    (note: you can select multiple objects at once and perform the same operations on multiple of them. To unselect all objects, click on empty space)

---

    For the following, press up/down for z value change, left/right for x value change, and shift + up/down for y value change:

    Press 't' to lock the camera and enter object translation mode (use arrow keys to move object)

    Press 'r' to lock the camera and enter object rotation mode (use arrow keys to rotate object)

    Press 'y' to lock the camera and enter object scaling mode (use arrow keys to scale object)

    Press 'u' to unlock the camera and return to normal mode

---

    Not fully supported yet:

    Press 'm' or 'M' to change display mode (Orthagonal, Perspective, First Person)

    W, A, S, D - move camera around in first person mode

---

Most of my work has been done on the systems behind managing objects but most of it is in a functional state to be able to focus entirely on complex objects now. Admittedly, I haven't spent as much time as I should have on the variety of 3D objects in my scene but as stated, I am shifting my entire focus on it. I expect to have a lot more complex geometry with source textures for them for the final submission and a proper lighting implementation with bug fixes here and there. I also plan to add a quick system to quickly place new objects into the scene. A lot of work has gone into designing color picking in order to manipulate 3d objects during runtime while attempting to make the scene easily viewable and manageable with changes to rendering and camera work. A large portion of my work has also been to speed up my modeling of 3D objects by building tools for myself such as automatic texture mapping and reducing the amount of vertices I need to manipulate to create complex shapes.

Credit to Willem A. (Vlakkies) Schreuder for the starter code (from various CSCI-4229 examples) and for the CSCI-x229 library.

Credit to opengl-tutorial.org for guidance on [colors picking](http://www.opengl-tutorial.org/miscellaneous/clicking-on-objects/picking-with-an-opengl-hack/)

In general, my linear algebra work on this project was done from background knowledge and from the wikipedia page on [rotation matrices](https://en.wikipedia.org/wiki/Rotation_matrix).

More information gathered for getting inputs for the camera were retrieved from the [Glut page from the openGL website](https://www.opengl.org/resources/libraries/glut/)

Credit to 3Blue1Brown for the video on how to [change vector basis](https://youtu.be/P2LTAUO1TdA?si=3wQlK2JkL9tRRthN) used for the pipe objects in this project