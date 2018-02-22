## Fun With Qt
Generating UI elements dynamically within a scrolling widget using Qt.

### About

While working on a personal project, I realised I'd need to generate UI elements in Qt based on information to be retrieved from a database. I put this code together (with help from Qt Documentation!) as a proof of concept and for others to use, modify, and build on freely. It shows one way of programmatically creating multiple buttons based on the value of an `int` passed into the `MainWindow` object, and how to connect these buttons to a single slot for event handling while being able to differentiate between them. 
