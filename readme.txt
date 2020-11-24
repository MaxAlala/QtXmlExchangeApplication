
в папке source находятся весь исходный код проекта.
Чтобы открыть проект и запустить его в qt creator: 
* выберите File-> Open File or Project выберите файл с разрешением .pro  
* нажмите кнопку Run( слева снизу)

в папке program есть две папке с .exe файлами для запуска на window.
**client_with_gui_release
Здесь просто запускаете client_with_gui.exe,
где можете подключиться к выбранному серверу
и запросить XML параметры.

**server_with_gui_release
вместе с server_with_gui.exe тут есть 
папка xml_messages, где хранятся два
xml сообщения. 
***messageWithEarthImage.xml содержит маленькую картинку,
***messageWithMarsImage.xml содержит большую картинку.
Тут в программе вы можете выбрать XML файл и запустить сервер на определенном
порту. 

Если хотите добавить картинку в XML файл,
то раскомментируйте строки

    // if you want to add an image data to the XML file to "image" element uncomment line below
    //            QString imagePath = ":/resources/images/earth.bmp";
    //            addImageToXML_Doc(document, imagePath);

в void MainWindow::readXmlParametersAndFitImage() в папке server_with_gui в файле mainwindow.cpp
и закомментируйте все строки ниже в этом методе.
В imagePath добавьте путь к вашей картинке.
Формат XML файла должен быть как в XML файлах упомянутых выше.
Соберите программу и запустите, нажмите выбрать XML file и картинка будет добавлена туда. Потом опять сделайте как было.