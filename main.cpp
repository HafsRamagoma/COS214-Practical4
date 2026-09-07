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


}
