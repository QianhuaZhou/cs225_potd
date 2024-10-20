#include <iostream>
#include "OfficeHour.h"

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    // Your code here!
    vector<int> time(onDutyStaff.size(), 0);
    if(onDutyStaff.empty()) return -1;
    int count = 1;
    while(!queue.empty() && count <= nthStudent){
        Student s = queue.front();
        queue.pop();
        int chosenIdx = -1;
        for(unsigned int i = 0; i < time.size(); ++i){
            if((chosenIdx == -1 || time[i] < time[chosenIdx]) && onDutyStaff[i].getEnergyLevel() > 0){
                chosenIdx = i;
            }
        }
        std::cout << std::endl;
        if(chosenIdx == -1) return -1;
        if(count == nthStudent) return time[chosenIdx];
        time[chosenIdx] += onDutyStaff[chosenIdx].answerQuestion(s.getQuestionType(), s.getTimeNeeded());
        count ++;
    }
    return -1;
}
