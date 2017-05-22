//
// Created by moje konto on 2017-05-19.
//

#include <cstddef>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

namespace academia {
    class SchedulingItem {
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    public:
        SchedulingItem(int course_id,int teacher_id,int room_id,int time_slot,int year);
        int CourseId() const { return course_id;};
        int TeacherId() const { return teacher_id;};
        int RoomId() const { return room_id;};
        int TimeSlot() const { return time_slot;};
        int Year() const { return year;};

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
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
