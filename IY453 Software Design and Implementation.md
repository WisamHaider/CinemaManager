# IY453 Software Design and Implementation

## Contents:

- Introduction

- Analysis and Design
  
  - First Stage: Outline program specification.
  
  - Second Stage: Indentify inputs, output, and processes.
  
  - Third Stage: Algorithm.

- References

## Introduction

The aim of the program is to create a cinema booking system made for the staff, to put very simply it will be used to handle the booking, the movie schedule and generate reports for the managers and staff at the cinema. The system will be written in C++17 or later and feature memory saved in csv files locally with a simple GUI.

#### First Stage:

###### Core program functions:

- Handle ticket booking:
  
  - Take information such as the ticket type, (adult, child, student, senior), film name, time booked.

- Cinema room and seating handling:
  
  - After information is taken properly display the available seats (allow selection) and displayed within the corresponding screen respective of the film.

- Allow managers to enter film details and generate a weekly schedule:
  
  - Ensure the system allows the manager to pick and choose the times within the time the cinema is open.

- Memory:
  
  - Save the schedule of each week, and save the bookings by all the customers, along with that allow customers to search from the schedule so they can find the film and at what time they would like to choose.

###### System Limitations and rules

**Passenger types**: There are 4 types, adult, student, senior and child.

**Screens**: There are only 5 screens of varying number of seatings.

**Gaps**: There will be a 25 minute gap between each movie to clean.

**Schedule**: Movies can only show within the open times of the cinema from 10 - 23:30 and the first showing can be at 10:15.

**Prices and movies**: Set from a given data set.

#### Second stage:
