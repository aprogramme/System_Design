# System Design
System design is the process of defining the architecture, components, modules, interfaces, and data for a system to meet specific requirements. It's a blueprint that guides the implementation phase, ensuring the system is built to be functional, reliable, and scalable. Key aspects include defining the system's structure (architecture), its constituent parts (components and modules), how those parts interact (interfaces), and how data will be handled. 

## OOPs (Object Oriented Programmings)
1. Abstraction
   > Abstraction hides unnecessary implementation details from the client and exposes 
      only what is essential to use an object’s functionality.
2. Encapsulation
   > Encapsulation bundles an object’s data (its state) and the methods that operate on 
     that data into a single unit, and controls access to its inner workings.
3. Inheritance
   > Real-world objects are often related in parent-child relationships. 
   > Example: Object A (Parent) and Object B (Child) share properties. 
   > In programming, this relationship is mimicked using Inheritance. 
5. Polymorphism
   > Derived from: "Poly" (many) + "Morph" (forms) = many forms. 
   > One stimulus → different responses based on object/situation.

## UML Diagram
A UML diagram, based on the Unified Modeling Language, is a visual representation of a system's structure and behavior, used primarily in software and systems engineering.

1.Class Diagram
<img width="1117" height="880" alt="Image" src="https://github.com/user-attachments/assets/73e878b1-b5d3-46ee-86d1-5b986dc5b068" />
2.Association
<img width="1117" height="795" alt="Image" src="https://github.com/user-attachments/assets/185857e6-2c40-42e6-bf53-c87ed3b55ad9" />
<img width="1092" height="658" alt="Image" src="https://github.com/user-attachments/assets/9a860661-be73-4618-a032-2f3e2522440a" />
3.Composition
<img width="807" height="848" alt="Image" src="https://github.com/user-attachments/assets/910fa69e-53e3-4a46-9c88-95581c27cf67" />
<img width="773" height="822" alt="Image" src="https://github.com/user-attachments/assets/e3afdb6e-f8bf-49c6-93df-30627008009c" />
4.Sequence Diagram
<img width="697" height="655" alt="Image" src="https://github.com/user-attachments/assets/08cca8f6-3262-4d5e-9358-b12b8b34a5f9" />
<img width="753" height="872" alt="Image" src="https://github.com/user-attachments/assets/cdb148e5-0384-4a69-9f14-d675c4ad5b0c" />

5.ATM Transaction

<img width="651" height="686" alt="Image" src="https://github.com/user-attachments/assets/ef18d36c-7483-4858-b210-b9ea970418da" />

9. ATM Transaction Diagram
<img width="1219" height="836" alt="Image" src="https://github.com/user-attachments/assets/54f3b10a-46be-473a-8afb-1668738c6394" />

## SOLID Diagram
In system design, SOLID refers to a set of five object-oriented design principles that aim to make software more understandable, flexible, and maintainable. These principles, encapsulated in the acronym SOLID, are: Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, and Dependency Inversion. 
### Here's a breakdown of each SOLID principle:
    1. Single Responsibility Principle (SRP):
   A class should have one, and only one, reason to change. This means a class should have a single responsibility or task. 
   
    2. Open/Closed Principle (OCP): 
   Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. This means you should be able to add new functionality without altering existing code. 
    
    3. Liskov Substitution Principle (LSP): 
   Objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program. 

    4. Interface Segregation Principle (ISP): 
   Clients should not be forced to depend on methods they do not use. This means creating smaller, more specific interfaces rather than one large, all-encompassing interface. 

    6. Dependency Inversion Principle (DIP): 
   High-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions. 
