Github repo for an Engineering Drawing Software desgined as the project for the course COP290 - Design Practices in CS (https://www.cse.iitd.ac.in/~suban/COP290/semII-2017-2018//) taught in Semester II, 2017-2018 at Indian Institute of Technology(IIT), Delhi.

### Rough Specification

Design and implement a software package for Engineering drawing. The package should have the following functionalities:

1. We should be able to interactively input or read from a file either i) an isometric drawing and a 3D object model or ii) projections on to any cross section.
2. Given the 3D model description we should be able to generate projections on to any cross section or cutting plane.
3. Given two or more projections we should be able to interactively recover the 3D description and produce an isometric drawing from any view direction. 

### Project Timeline

#### Step I: Modeling and analysis
- Work out a mathematical model for the problem. Figure out how many views are necessary? how many are sufficient? How can one compute projections given the 3D description? How can one compute the 3D description given one or more projections? What interactions are necessary?
- Define the problem more precisely and submit a LaTex report by Jan 18.

#### Step II: Software requirement specification
- Capture the functional specification in UML and submit by Feb 14. Be as comprehensive as possible.

#### Step III: Software design document
- Specify the software architecture for program development using C++ including class diagrams and function prototypes in Doxygen and submit by March 5.

#### Step IV: Implementation and software documentation
- Please study the following tools and commands: C pre-processor, steps in gcc compilation, linking (static and dynamic linking), Makefile, nm, objdump, strip, ldconfig, ldd, ar and ranlib. And, of course, Git and SVN. Please refer to

    1. The ``hello world'' examples in http://web.iitd.ernet.in/~suban/COP290/stuff.
    2. https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html.
    3. http://www.cse.iitd.ac.in/~avinash/ta.html.
    4. http://www.cse.iitd.ac.in/~subhajit/csp301.shtml. 

- Please submit a tar ball containing your software implementation and documentation by March 18.
#### Step V: Testing and fine tuning

#### Step VI: Report
