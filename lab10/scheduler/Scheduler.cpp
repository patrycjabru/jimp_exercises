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

    }

    SchedulingItem Schedule::operator[](int it) const {
        return item_[it];
    }

    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
            this->course_id=course_id;
            this->teacher_id=teacher_id;
            this->room_id=room_id;
            this->time_slot=time_slot;
            this->year=year;

    }
}