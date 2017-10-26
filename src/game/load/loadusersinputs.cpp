/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

#include "users/usersinputs.h"
#include "utilities/conversion.h"
#include "load/loadusersinputs.h"
#include "utilities/logging.h"

// static declarations
usersInputsVecSharedPtr loadUsersInputs::uiInstance;
stdStringVec loadUsersInputs::usersInputFiles;
bool loadUsersInputs::userInputFilesLoaded;

loadUsersInputs::loadUsersInputs()  // constructor
{
    userInputFilesLoaded = false;

}
loadUsersInputs::~loadUsersInputs()  // destructor
{

}

stdStringVec loadUsersInputs::getUsersInputFiles()   // retrieves the value of userInputFiles
{
    return (usersInputFiles);
}
void loadUsersInputs::setUsersInputFiles(stdStringVec set)  // sets the value of userInputFiles
{
    usersInputFiles = set;
}

usersInputsVecSharedPtr loadUsersInputs::getUIInstance()  // retrieves the value of uoInstance
{
    return(uiInstance);
}
void loadUsersInputs::setUIInstance(usersInputsVecSharedPtr set)  // sets the value of uiInstance
{
    uiInstance = set;
}

bool loadUsersInputs::getUsersInputFilesLoaded()  // retrieves the value of userInputFilesLoaded
{
    return (userInputFilesLoaded);
}
void loadUsersInputs::setUsersInputFilesLoaded(bool set)  // sets the value of userInputFilesLoaded
{
    userInputFilesLoaded = set;
}

bool loadUsersInputs::checkIfUsersInputsLoaded()  // checks if user inputs have been loaded into pInstance
{
        sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "loadUsersInputs::checkIfUserInputsLoaded()";

    logMsg(func +" beginning");

    if (userInputFilesLoaded)
    {
        logMsg(func +" getUserInputFilesLoaded");

        if (uiInstance.size() > 0)
        {
            logMsg(func +" User Input Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func +" User Input Files not yet Loaded!");

            userInputFilesLoaded = false;
            uiInstance = loadUsersInputFiles();
            if (uiInstance.size() > 0)
            {
                logMsg(func +" uiInstance.size() ==" +convert->toString(uiInstance.size()));

//                load->setTInstance(tInstance);
                userInputFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load User Input Files! IF");
                exit(0);
            }
        }
    }
    else
    {
        logMsg(func +" ELSE");

        if (uiInstance.size() > 0)
        {
            logMsg(func +" uiInstance.size() ==" +convert->toString(uiInstance.size()));
//            load->setTInstance(tInstance);
            userInputFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func +" ELSE ELSE!");

            uiInstance = loadUsersInputFiles();
            logMsg("loader::checkIfUserInputsLoaded()");
            if (uiInstance.size() > 0)
            {
                logMsg(func +" uiInstance.size() ==" +convert->toString(uiInstance.size()));

//                load->setTInstance(tInstance);
                userInputFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load User Input Files!");
                return(false);
            }
            exit(0);
        }
    }

    logMsg(func +" end");

    return (false);
}

// User input
usersInputsVecSharedPtr loadUsersInputs::loadUsersInputFiles()  // load user input settings from XML files
{
    sharedPtr<conversion> convert = conversion::Instance();
    usersInputsVecSharedPtr usersInputs;
    usersInputsSharedPtr input;
    std::string usersInputList;
    std::string func = "loadUsersInputs::loadUserInputs()";

    logMsg(func +" beginning");

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    usersInputList = "data/users/inputlist.xml";
#else
    usersInputList = findFile("users/inputlist.xml");
#endif
//    exit(0);
    usersInputFiles = loadUsersInputListFile(usersInputList);
//    stdStringVec playerFiles = load->getPlayerFiles();
//    exit(0);
    stdStringVec::iterator it;
    for (it = usersInputFiles.begin(); it != usersInputFiles.end(); ++it)
    {
        logMsg(func +" userInputFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        usersInputs.push_back(loadUsersInputFile("data/users/" + *it));
        input = loadUsersInputFile("data/users/" + *it);
        logMsg(func +" input quit == " +convert->toString(input->getKeyQuit()));

#else
        usersInputs.push_back(loadUsersInputFile(findFile("users/" + *it)));
#endif
    }
    logMsg(func +" quit == " +convert->toString(usersInputs[0]->getKeyQuit()));
//    exit(0);
    logMsg(func +" end");
    return (usersInputs);
}

stdStringVec loadUsersInputs::loadUsersInputListFile(std::string fileName)  // loads the user input list file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    stdStringVec uInputFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loadUsersInputs::loadUserInputListFile()";

    logMsg(func +" beginning");

    logMsg(func + " " +fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    
    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse inputlist.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }
    
    
    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg(func +" Unable to find avalid root for user input list file!");
    } 
    
    // save this for later
    hRoot=tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        std::string pKey=pElem->Value();
        logMsg(func +" pKey == " +pKey);
        std::string pText=pElem->GetText();
        logMsg(func +" pText == " +pText);
        uInputFiles.push_back(pText);
    }
    logMsg(func +" uInputFiles.size() == " +convert->toString(uInputFiles.size()));
//    exit(0);
//    setUserInputFiles(userInputFile);
//    return true;

    logMsg(func +" end");
    return (uInputFiles);
}

usersInputsSharedPtr loadUsersInputs::loadUsersInputFile(std::string fileName)  // loads data from the user input files
{
    sharedPtr<conversion> convert = conversion::Instance();
    const sharedPtr<usersInputs> uInput(new usersInputs);
    std::string inputName;
    std::string type;
    std::string up;
    std::string down;
    std::string left;
    std::string right;
    std::string upLeft;
    std::string upRight;
    std::string downLeft;
    std::string downRight;
    std::string shootBlock;
    std::string passSteal;
    std::string pause;
    std::string startSelect;
    std::string quit;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    std::string func = "loadUsersInputs::loadUserInputFile()";

    logMsg(func +" beginning");
    logMsg(func +" Load UserInput File");
   
    readFile(fileName.c_str(), &contents);
    logMsg(func +" readFile successful!");

    fileContents = convert->toString(contents);
    logMsg(func +" fileContents = " +fileContents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg(func +" Unable to parse user input file");
/*        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
  }
    
    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLElement *nextChild;
    tinyxml2::XMLHandle hRoot(0);

    logMsg(func +" rootElement=hDoc.FirstChildElement().ToElement()");

    rootElement=hDoc.FirstChildElement().ToElement();   
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg(func +" Unable to load user input element");
        exit(0);
    }

    logMsg(func +" child = rootElement->FirstChild()->ToElement()");

    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        logMsg(func +" if (cKey == 'Name')");
        if (cKey == "Name")
        {
            inputName = child->GetText();
//            logMsg("name = " +inputName);
        }
        
        bool inputTag = false;
        logMsg(func +"while (!inputTag)");
        while (!inputTag)
        {
            logMsg(func +" child = child->NextSiblingElement()->ToElement()");
            child = child->NextSiblingElement()->ToElement();
            if (child)
            {
                logMsg(func +" nextChild = child->FirstChildElement()->ToElement()");
                nextChild = child->FirstChildElement()->ToElement();
                inputTag = true;
                logMsg(func +" for( nextChild; nextChild; nextChild=nextChild->NextSiblingElement())");
                for( nextChild; nextChild; nextChild=nextChild->NextSiblingElement())
                {
                    std::string pKey=nextChild->Value();
//                    logMsg("pKey = " +pKey);
//                    exit(0);
                    if (pKey == "Type")
                    {
                        type = nextChild->GetText();
//                        logMsg("type = " +type);
//                        exit(0);
                    }
                    if (pKey == "Up")
                    {
                        up = nextChild->GetText();
//                        logMsg("up = " +up);

                    }
                    if (pKey == "Down")
                    {
                        down = nextChild->GetText();
                    }
                    if (pKey == "Left")
                    {
                        left = nextChild->GetText();
                    }
                    if (pKey == "Right")
                    {
                        right = nextChild->GetText();
                    }
                    if (pKey == "UpLeft")
                    {
                        upLeft = nextChild->GetText();
                    }
                    if (pKey == "UpRight")
                    {
                        upRight = nextChild->GetText();
                    }
                    if (pKey == "DownLeft")
                    {
                        downLeft = nextChild->GetText();
                    }
                    if (pKey == "DownRight")
                    {
                        downRight = nextChild->GetText();
                    }
                    if (pKey == "ShootBlock")
                    {
                        shootBlock = nextChild->GetText();
                    }
                    if (pKey == "PassSteal")
                    {
                        passSteal = nextChild->GetText();
                    }
                    if (pKey == "Pause")
                    {
                        pause = nextChild->GetText();
                    }
                    if (pKey == "StartSelect")
                    {
                        startSelect = nextChild->GetText();
//                        exit(0);
                    }
                    if (pKey == "Quit")
                    {
                        quit = nextChild->GetText();
                        logMsg(func +" Quit key == " +quit);
//                        exit(0);
                    }
                }
            }
            else
            {
                inputTag = false;
            }
//            modelName = child->GetText();
//            logMsg("modelName = " +modelName);
            
            uInput->setName(inputName);
            uInput->setType(convert->toInputType(type));

            switch (uInput->getType())
            {
                case KEYBOARD:
                    uInput->setKeyUp(convert->toInputKey(up));
                    uInput->setKeyDown(convert->toInputKey(down));
                    uInput->setKeyLeft(convert->toInputKey(left));
                    uInput->setKeyRight(convert->toInputKey(right));
                    uInput->setKeyUpLeft(convert->toInputKey(upLeft));
                    uInput->setKeyUpRight(convert->toInputKey(upRight));
                    uInput->setKeyDownLeft(convert->toInputKey(downLeft));
                    uInput->setKeyDownRight(convert->toInputKey(downRight));
                    uInput->setKeyShootBlock(convert->toInputKey(shootBlock));
                    uInput->setKeyPassSteal(convert->toInputKey(passSteal));
                    uInput->setKeyPause(convert->toInputKey(pause));
                    uInput->setKeyStartSelect(convert->toInputKey(startSelect));
                    uInput->setKeyQuit(convert->toInputKey(quit));
                    logMsg(func +" quit == " +convert->toString(uInput->getKeyQuit()));
    //                exit(0);
                break;
                case GAMEPAD:
                // FIXME! mapping needs to be implemented
    /*                uInput->setGPUp(up);
                    uInput->setGPDown(down);
                    uInput->setGPLeft(left);
                    uInput->setGPRight(right);
                    uInput->setGPUpLeft(upLeft);
                    uInput->setGPUpRight(upRight);
                    uInput->setGPDownLeft(downLeft);
                    uInput->setGPDownRight(downRight);
                    uInput->setGPShootBlock(shootBlock);
                    uInput->setGPPassSteal(passSteal);
                    uInput->setGPPause(pause);
                    uInput->setGPStartSelect(startSelect);
    */
                break;
                case MOUSE:
                break;
                case TOUCH:
                break;
            }
        }
    }

    logMsg(func +" quit == " +convert->toString(uInput->getKeyQuit()));
//    exit(0);
    logMsg(func +" end");

    return (uInput);
}
