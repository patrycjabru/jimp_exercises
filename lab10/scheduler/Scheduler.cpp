//
// Created by moje konto on 2017-05-19.
//

#include "Scheduler.h"

namespace academia {
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
        this->course_id=course_id;
        this->teacher_id=teacher_id;
        this->room_id=room_id;
        this->time_slot=time_slot;
        this->year=year;
    }

    int SchedulingItem::CourseId() const {
        return course_id;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id;
    }

    int SchedulingItem::RoomId() const {
        return room_id;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot;
    }

    int SchedulingItem::Year() const {
        return year;
    }

    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {

        std::vector<std::vector<int>> vec(n_time_slots);
        int course_id = 0, teacher_id = 0, room_id = 0, time_slot = 0, year = 0;
        int slots = n_time_slots;
        bool flag = false;
        int room = 0;
        Schedule sched;

        for (auto x : teacher_courses_assignment) {
            teacher_id = x.first;
            for(auto y : x.second) {
                course_id = y;
                if(slots <= 0)
                {
                    slots = n_time_slots;
                    room++;
                }
                if(rooms.size() < room + 1)
                    throw NoViableSolutionFound();
                room_id = rooms[room];
                for (auto z : courses_of_year) {
                    for(auto c : z.second) {
                        if(c == y)
                        {
                            year = z.first;
                            vec[slots-1].push_back(year);
                            flag = true;
                            break;
                        }
                    }
                    if(flag) {
                        break;
                    }
                }
                if(!flag)
                    throw NoViableSolutionFound();
                else
                    flag = false;
                sched.InsertScheduleItem(SchedulingItem{ course_id, teacher_id, room_id,slots, year } );
                slots--;
            }
        }

        for(auto &a : vec)
        {
            std::sort(a.begin(), a.end());
            auto p = std::unique(a.begin(), a.end());
            if(p != a.end())
            {
                throw NoViableSolutionFound();
            }
        }

        return sched;
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule tmp;
        std::copy_if (item_.begin(), item_.end(), std::back_inserter(tmp.item_),
                      [teacher_id](SchedulingItem it ) { return teacher_id==it.TeacherId(); } );
        return tmp;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule tmp;
        std::copy_if (item_.begin(), item_.end(), std::back_inserter(tmp.item_),
                      [room_id](SchedulingItem it ){return room_id==it.RoomId();} );
        return tmp;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule tmp;
        std::copy_if (item_.begin(), item_.end(), std::back_inserter(tmp.item_),
                      [year](SchedulingItem it ){return (year==it.Year());} );
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
}