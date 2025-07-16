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
   >A class should have one, and only one, reason to change. This means a class should have a single responsibility or task. 
   
2. Open/Closed Principle (OCP): 
   >Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. This means you should be able to add new functionality without altering existing code. 
    
3. Liskov Substitution Principle (LSP): 
   >Objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program. 

4. Interface Segregation Principle (ISP): 
   >Clients should not be forced to depend on methods they do not use. This means creating smaller, more specific interfaces rather than one large, all-encompassing interface. 

5. Dependency Inversion Principle (DIP): 
   >High-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions. 

## Creating Document Editor
<img width="1635" height="1006" alt="Image" src="https://github.com/user-attachments/assets/52ed7a75-0652-40fb-808d-da2a376949eb" />

## Strategy Design Pattern
1.

<img width="907" height="596" alt="Image" src="https://github.com/user-attachments/assets/15a7acfd-3577-47cc-8f57-18a85e9ee846" />

2.

<img width="1004" height="846" alt="Image" src="https://github.com/user-attachments/assets/cb3b4106-26fb-41dc-b623-f727d5093a5d" />

3

<img width="1541" height="771" alt="Image" src="https://github.com/user-attachments/assets/4c03094c-adb9-4fa1-8089-74594a23349d" />

4

<img width="1299" height="840" alt="Image" src="https://github.com/user-attachments/assets/f5069869-ef5c-4974-bdd8-f613ebd7732c" />

5

<img width="1371" height="613" alt="Image" src="https://github.com/user-attachments/assets/6fcf02ef-05a0-47e6-bc3b-005bd6364183" />

6

<img width="1508" height="710" alt="Image" src="https://github.com/user-attachments/assets/7acd5af7-734b-41e8-9948-7a61bb47c143" />

### Problem with Inheritance
>Code Re-use

>To add new feature a lot of changes were required

>Breaking OCP

### Strategy Design Pattern
Defines a family of Algorithm, put them into separate classes so that they can be changed at run time.
<img width="782" height="545" alt="Image" src="https://github.com/user-attachments/assets/3c45de64-be5f-4bb3-abe9-9a9c65fa7640" />


<img width="1707" height="691" alt="Image" src="https://github.com/user-attachments/assets/0404ca69-0798-4f88-8cfc-fac3a3433fd4" />


<img width="1606" height="717" alt="Image" src="https://github.com/user-attachments/assets/2e389b99-ddf0-4506-aa37-d2f86da9f9b9" />


<img width="1097" height="836" alt="Image" src="https://github.com/user-attachments/assets/aae76916-9909-4018-8438-4f4ad7abdb8f" />


<img width="1626" height="427" alt="Image" src="https://github.com/user-attachments/assets/ded6a23e-7f52-44e5-b910-35a56d0c210f" />


<img width="1529" height="532" alt="Image" src="https://github.com/user-attachments/assets/1985d41a-c1b4-4ce1-8472-c31d093df31d" />

## Build Zomato food delivery app
### UML of app
<img width="2732" height="1645" alt="Image" src="https://github.com/user-attachments/assets/d531752e-a584-47cc-a3fc-2e62b65a2d84" />

## Observer Design Pattern
Defines a one-to-many relationship b/w objects so that when one object changes state, all of its dependents are notified and update automatically.
![Image](https://github.com/user-attachments/assets/a5cbce91-5cca-404d-b851-f9a54a383406)

## Decorator Design Pattern
Decorator pattern attaches additional responsibilities to an object dynamically decorator provides a flexible alternative to subclassing for extending functionality.
![Image](https://github.com/user-attachments/assets/324d35f2-3364-4ced-a53a-7d7c6ad87d5b)
