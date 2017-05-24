//
// Created by moje konto on 2017-05-19.
//

#include "Scheduler.h"
namespace academia {

    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {
        for (auto c : courses_of_year) {
            int numberOfCourse = c.first;
            for (auto x : c.second) {
                int year = x;
                //znajdz nauczyciela
                //znajdz sale

            }

        }
        return Schedule();
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule tmp;
        std::copy_if (item_.begin(), item_.end(), std::back_inserter(tmp.item_), [teacher_id](SchedulingItem it ){return teacher_id==it.TeacherId();} );
        return tmp;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule tmp;
        std::copy_if (item_.begin(), item_.end(), std::back_inserter(tmp.item_), [room_id](SchedulingItem it ){return room_id==it.RoomId();} );
        return tmp;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule tmp;
        std::copy_if (item_.begin(), item_.end(), std::back_inserter(tmp.item_), [year](SchedulingItem it ){return (year==it.Year());} );
        return tmp;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        item_.push_back(item);
    }

    SchedulingItem Schedule::operator[](int it) const {
        return item_[it];
    }

    size_t Schedule::Size() const {
        return item_.size();
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int>tmp;
        for(int i=1;i<n_time_slots+1;i++)
            tmp.push_back(i);
        for(auto& n :item_)
        {
            auto notAvailable=std::find(tmp.begin(),tmp.end(),n.TimeSlot());
            if(notAvailable!=tmp.end())
                tmp.erase(notAvailable);
        }
        return tmp;
    }

    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
            this->course_id=course_id;
            this->teacher_id=teacher_id;
            this->room_id=room_id;
            this->time_slot=time_slot;
            this->year=year;

    }
}