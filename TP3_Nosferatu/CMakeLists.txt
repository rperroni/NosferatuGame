cmake_minimum_required(VERSION 3.16.3)
project(grafos)

set(CMAKE_CXX_STANDARD 20)

add_executable(simon
        main.cpp
        Vertex.cpp Vertex.h
        List.h Node.h
        Cell.cpp Cell.h
        Mountain.cpp Mountain.h
        Lake.cpp Lake.h
        Cliff.cpp Cliff.h
        Volcano.cpp Volcano.h
        Road.cpp Road.h
        TheVoid.cpp TheVoid.h
        Object.h Object.cpp
        Being.h Being.cpp
        Human.h Human.cpp
        Bullet.h Bullet.cpp
        Cross.cpp Cross.h
        Element.h
        HolyWater.h HolyWater.cpp
        Monster.h
        Nosferatu.h Nosferatu.cpp
        Vampire.h Vampire.cpp
        Shotgun.h Shotgun.cpp
        Stake.h Stake.cpp
        Hunter.h Hunter.cpp
        Vampirella.h Vampirella.cpp
        Vanesa.h Vanesa.cpp
        Zombie.h Zombie.cpp
        Floyd.cpp Floyd.h
        Battle.cpp Battle.h
        Map.h Matrix.h
        estado.txt
        BoardFile.cpp BoardFile.h
        ObjectFile.cpp ObjectFile.h
        FileManager.cpp FileManager.h
        SaveGameFile.cpp SaveGameFile.h
        ObjectIncludes.h constantsNames.h
        ObjectCreator.cpp ObjectCreator.h
        Map.cpp
        colors.h
        ObjectAdder.cpp
        ObjectCreator.h
        Gotoxy.h
        MapCreator.cpp MapCreator.h
        CostMatrices.cpp CostMatrices.h
        Game.cpp Game.h
        Inventory.cpp Inventory.h
        Element.cpp
        UserInput.cpp UserInput.h
        Dictionary.cpp Dictionary.h
        DictNode.cpp DictNode.h
        Printer.cpp Printer.h
        Simulation.cpp Simulation.h
        Menu.cpp Menu.h
        Identifier.cpp Identifier.h
        Player.cpp Player.h
        SimulationMenu.cpp SimulationMenu.h
        QuadrantSearch.h QuadrantSearch.cpp
        Monster.cpp)