//
// Created by moje konto on 2017-05-19.
//a

#include <cstddef>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

namespace academia {
    class SchedulingItem {
    public:
        SchedulingItem(int course_id,int teacher_id,int room_id,int time_slot,int year);

        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };

    class Schedule {
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        SchedulingItem operator[](int it) const;
        std::vector<SchedulingItem> item_;
    };

    class Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };

    class GreedyScheduler : public Scheduler {
    public:
        GreedyScheduler() {};
        virtual ~GreedyScheduler() {};
    };

    class NoViableSolutionFound : public std::runtime_error {
    public:
        NoViableSolutionFound() : std::runtime_error("Can't create schedule") {};
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
