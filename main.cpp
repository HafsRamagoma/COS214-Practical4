#include "Blocked.h"
#include "Cancelled.h"
#include "Completed.h"
#include "DepthFirstIterator.h"
#include "FilmComponent.h"
#include "FilmIterator.h"
#include "InProgress.h"
#include "NeedsReshoot.h"
#include "NotStarted.h"
#include "OvertimeDecorator.h"
#include "PendingtaskIterator.h"
#include "SafetyDecorator.h"
#include "TaskDecorator.h"
#include "TaskItem.h"
#include "TaskState.h"
#include "WorkGroup.h"
#include "EquipmentDecorator.h"


void taskTesting(){
    std::cout<<"Testing all states:"<<std::endl;

    TaskItem* filming = new TaskItem("Scene 1 Filming",1000.0);
    filming->print();

    std::cout<< "\nAttempting to complete before starting..."<<std::endl;
    filming->getCurrentState()->complete();
    filming->print();

    std::cout<<"\nStarting the task..."<<std::endl;
    filming->getCurrentState()->start();
    filming->request();


    std::cout << "\nBlocking the task..."<<std::endl;
    filming->getCurrentState()->block();
    filming->print();

    std::cout<<"\nResuming and completing.."<<std::endl;
    filming->getCurrentState()->resume();
    filming->getCurrentState()->complete();
    filming->print();

    std::cout<<"Testing iterator with the state"<<std::endl;
    WorkGroup* project = new WorkGroup("Mini Project");
    project->add(filming);

    TaskItem* script = new TaskItem("Script writing",500.0);
    project->add(script);

    std::cout<<"Current Pending Tasks (Completed tasks shouldn't show)"<<std::endl;
    FilmIterator* it = project->createPendingTaskIterator();
    it->first();
    while(!it->isDone()){
        std::cout << "--" << it->currentItem()->getName() << std::endl;
        it->next();
    }

    delete it;
    delete project;

}


int main(){
    FilmComponent* movieProject = new WorkGroup ("Move: Adventure with the Bois and Gal");

    WorkGroup* preProduction = new WorkGroup("Pre-Production Phase");
    WorkGroup* production = new WorkGroup("Production Phase");
    WorkGroup* postProduction = new WorkGroup("Post-Production Phase");

    TaskItem* script = new TaskItem("Write Script", 5000.0);
    TaskItem* casting = new TaskItem("Casting Call", 2000.0);

    preProduction->add(script);
    preProduction->add(casting);

    TaskItem* filming = new TaskItem("Main Filming", 50000.0);
    TaskItem* lighting = new TaskItem("Set Lighting", 1500.0);
    production->add(filming);
    production->add(lighting);

    TaskItem* editing = new TaskItem("Video Editing", 8000.0);
    TaskItem* sound = new TaskItem("Sound Mixing", 3000.0);
    postProduction->add(editing);
    postProduction->add(sound);

    movieProject->add(preProduction);
    movieProject->add(production);
    movieProject->add(postProduction);

    std::cout<< "Movie structure:"<<std::endl;
    movieProject->print();
    std::cout<< "Movie total budget"<<std::endl;
    std::cout<<movieProject->getCost()<<std::endl;

    std::cout<<"Pending tasks:"<<std::endl;
    FilmIterator* it = movieProject->createPendingTaskIterator();

    it->first();
    while(!it->isDone()){
        FilmComponent* current = it->currentItem();

        if(current){
            std::cout<<"Pending -" << current->getName() <<std::endl;

        }
        it->next();
    }

    delete it;

    delete movieProject;

    std::cout << "\nTesting Decorators:" << std::endl;

    FilmComponent* overtimeTask =
        new OvertimeDecorator(
            new TaskItem("Late Night Filming", 10000.0)
        );

    std::cout << "\nOvertime decorated task:" << std::endl;
    overtimeTask->print();
    std::cout << "Cost with overtime: " << overtimeTask->getCost() << std::endl;
    overtimeTask->request();


    FilmComponent* stackedTask =
        new EquipmentDecorator(
            new SafetyDecorator(
                new OvertimeDecorator(
                    new TaskItem("Stunt Scene", 15000.0)
                ),
                3
            ),
            "Camera Crane",
            2500.0
        );

    std::cout << "\nStacked decorated task:" << std::endl;
    stackedTask->print();
    std::cout << "Total decorated cost: " << stackedTask->getCost() << std::endl;
    stackedTask->request();

    delete overtimeTask;
    delete stackedTask;

    taskTesting();



    return 0;
}
