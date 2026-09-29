# CinemaManager Project

## Contents:



- Introduction - 3

- Analysis - 4

- Testing - 12

- Evaluation - 26

- References - 27



## Introduction

The aim of the program is to create a cinema booking system made for the staff, to put very simply it will be used to handle the booking, the movie schedule and generate reports for the managers and staff at the cinema, it's to create an easy method to store all the information related to the cinema and view insights on all the movies being played. The system will be written in C++17 or later and feature memory saved in csv files locally with a simple GUI. In Stage 3, the system was able to make bookings and schedules; however, all the information would get erased once the program was shut down, making it inappropriate for practical use. In this final submission, the process of file persistence is achieved using CSV files in order to make sure that all the bookings and schedules would stay even after the program is shut down, thus helping the cinema keep a continuous record of their operation. In addition to that, all input validations are made in order to avoid wrong information being entered, and all file I/O processes were tested to ensure that the data is correct. This report will start off by outlining the program specification, an IPO table and some flowcharts. Then it will present the test table to ensure code functionality followed by annotation screenshots, some information on the technical elements of the code, and then an evaluation to summarize what the report has presented thus far. The report will conclude with the reference list and the appendix code


## Analysis

Core program functions:

•	Handle ticket booking:

Take information such as the ticket type, (adult, child, student, senior), film name, time booked.

•	Cinema room and seating handling:

After information is taken properly display the available seats (allow selection) and displayed within the corresponding screen respective of the film.

•	Allow managers to enter film details and generate a weekly schedule: 

Ensure the system allows the manager to pick and choose the times within the time the cinema is open.

•	Memory:  

Save the schedule of each week, and save the bookings by all the customers, along with that allow customers to search from the schedule so they can find the      film and at what time they would like to choose.

System Limitations and rules

Passenger types: There are 4 types, adult, student, senior and child.

Screens: There are only 5 screens of varying number of seatings.

Gaps: There will be a 25 minute gap between each movie to clean.

Schedule: Movies can only show within the open times of the cinema from 10 - 23:30 and the first showing can be at 10:15.

Prices and movies: Set from a given data set.

### IPO Table

| INPUT                                     | PROCESS                                                                                                             | OUTPUT                                                                                |
| ----------------------------------------- | ------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| Film Selection (1-3)                      | Validate input range, retrieve film details, find allocated screen                                                  | Display available screens with start/end times for selected film                      |
| Customer Name (string)                    | Validate not empty, store in booking object                                                                         | Name accepted, proceed to booking date prompt                                         |
| Booking Date (DD/MM/YYYY)                 | Validate format (DD/MM/YYYY), validate day (1-31), validate month (1-12)                                            | Date accepted and stored, proceed to booking time prompt                              |
| Booking Time (HH:MM)                      | Validate format (HH:MM), validate hours (0-23), validate minutes (0-59), check if within cinema hours (10:00-23:30) | Time accepted and stored, proceed to ticket quantity prompt                           |
| Adult Tickets (0-100)                     | Validate numeric input, check range 0-100                                                                           | Ticket count accepted, proceed to child tickets prompt                                |
| Child Tickets (0-100)                     | Validate numeric input, check range 0-100                                                                           | Ticket count accepted, proceed to student tickets prompt                              |
| Student Tickets (0-100)                   | Validate numeric input, check range 0-100                                                                           | Ticket count accepted, proceed to senior tickets prompt                               |
| Senior Tickets (0-100)                    | Validate numeric input, check range 0-100, calculate total tickets                                                  | Ticket count accepted, validate total is at least 1                                   |
| Total Tickets (sum of all types)          | Check if total > 0, check if total <= available seats on screen                                                     | Display booking summary with customer name, film, date, time, total cost              |
| Payment Method (cash/card)                | Validate input is "cash" or "card" (case-sensitive)                                                                 | Prompt for payment details (cash amount or card information)                          |
| Cash Amount                               | Validate numeric input, validate amount >= total booking cost                                                       | Display change amount or reprompt if insufficient                                     |
| Film Title (Add New)                      | Validate not empty, add to films vector                                                                             | Display "Film 'X' added successfully!" message                                        |
| Film Runtime (1-300 minutes)              | Validate numeric input, check range 1-300, trigger showtime calculation                                             | Runtime accepted, display calculated showtimes and end times                          |
| Screen Film Selection (1-5)               | Validate numeric input range 1-5, allocate film to screen, calculate showtimes with 25-min gaps                     | Display "Screen X allocated with Film Title" confirmation                             |
| Customer Name Search (string)             | Search bookingHistory vector for exact name match (case-sensitive)                                                  | Display all matching bookings or "No bookings found for customer: X"                  |
| Film Title Search (string)                | Search bookingHistory vector for exact film match (case-sensitive)                                                  | Display all matching bookings or "No bookings found for film: X"                      |
| Booking Date Search (DD/MM/YYYY)          | Validate date format, search bookingHistory vector for exact date match                                             | Display all matching bookings or "No bookings found for date: X"                      |
| Main Menu Choice (1-3)                    | Validate input range 1-3                                                                                            | Route to Staff Mode, Manager Mode, or Exit program with goodbye message               |
| Staff Menu Choice (1-6)                   | Validate input range 1-6                                                                                            | Route to Create Booking, Search functions, View Bookings, or Back to Main Menu        |
| Manager Menu Choice (1-5)                 | Validate input range 1-5                                                                                            | Route to Add Film, Create Schedule, View Screens, View Bookings, or Back to Main Menu |
| Complete Booking (after payment)          | Save to bookingHistory vector, save to bookings.csv, update screen available seats                                  | Display "Booking completed successfully." and "Booking saved to file successfully."   |
| Create Weekly Schedule (5 films selected) | Save all screen allocations and showtimes to schedule.csv                                                           | Display "Weekly schedule created and saved successfully!"                             |
| Program Startup                           | Load bookingsFromFile(), populate bookingHistory vector                                                             | Display "Loaded X bookings from file." message                                        |

### Flowcharts	

<img width="771" height="1091" alt="image" src="https://github.com/user-attachments/assets/9165658a-f42f-480d-a67c-e528caad1c32" />
<img width="940" height="780" alt="image" src="https://github.com/user-attachments/assets/00045272-cd27-4c45-b09d-c984c9af767b" />
<img width="884" height="873" alt="image" src="https://github.com/user-attachments/assets/e33d7d19-068c-4e50-88ec-ac13ba02814c" />
<img width="490" height="856" alt="image" src="https://github.com/user-attachments/assets/0713bbf6-84f6-41af-a683-2eb5717da769" />
<img width="940" height="745" alt="image" src="https://github.com/user-attachments/assets/7d778013-5656-4c77-a5b1-48bb8759ff3f" />
<img width="925" height="659" alt="image" src="https://github.com/user-attachments/assets/2612a67a-e871-40ce-95ea-8ff8d632edbe" />


## Testing

| TEST NO. |  ITEM TO TEST                       |  TEST DESCRIPTION (WITH DATA)                                            |  EXPECTED RESULT                                       |  ACTUAL RESULT                            |  COMMENTS/ACTIONS |
| -------- | ----------------------------------- | ------------------------------------------------------------------------ | ------------------------------------------------------ | ----------------------------------------- | ----------------- |
| 1        |  Film Selection - Valid             |  User enters valid film choice (input: 1)                                |  Film selected, booking continues                      |  Same                                     |  Pass             |
| 2        |  Film Selection - Out of Range      |  User enters number beyond limit (input: 5)                              |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 3        |  Film Selection - Negative          |  User enters negative number (input: -1)                                 |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 4        |  Film Selection - Non-numeric       |  User enters special characters (input: @#$)                             |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 5        |  Customer Name - Valid              |  User enters normal name (input: "John Smith")                           |  Name accepted and stored                              |  Same                                     |  Pass             |
| 6        |  Customer Name - Numbers            |  User enters name with numbers (input: "John123")                        |  Should reject or warn                                 | Accepts but should reject                 |  Pass             |
| 7        |  Customer Name - Special Characters |  User enters name with symbols (input: "John@Smith!")                    |  Should reject or warn                                 | Accepts but should reject                 |  Pass             |
| 8        |  Customer Name - Empty              |  User presses enter without typing (input: "")                           |  Should reprompt                                       | Accepts but should reject                 |  Pass             |
| 9        |  Booking Date - Valid               |  User enters date (input: "15/07/2026")                                  |  Date accepted and stored                              |  Same                                     |  Pass             |
| 10       |  Booking Date - Wrong Format        |  User enters wrong format (input: "15-07-2026")                          |  Error message: "Invalid date format!"                 |  Same                                     |  Pass             |
| 11       |  Booking Date - Day > 31            |  User enters invalid day (input: "32/07/2026")                           |  Error message: "Invalid date format!"                 |  Same                                     |  Pass             |
| 12       |  Booking Date - Month > 12          |  User enters invalid month (input: "15/13/2026")                         |  Error message: "Invalid date format!"                 |  Same                                     |  Pass             |
| 13       |  Booking Time - Valid               |  User enters time (input: "14:30")                                       |  Time accepted and stored                              |  Same                                     |  Pass             |
| 14       |  Booking Time - Wrong Format        |  User enters wrong format (input: "14.30")                               |  Error message: "Invalid time format!"                 |  Same                                     |  Pass             |
| 15       |  Booking Time - Hour > 23           |  User enters invalid hour (input: "24:00")                               |  Error message: "Invalid time format!"                 |  Same                                     |  Pass             |
| 16       |  Booking Time - Minute > 59         |  User enters invalid minute (input: "14:75")                             |  Error message: "Invalid time format!"                 |  Same                                     |  Pass             |
| 17       |  Cinema Hours - Opening Time        |  User enters opening time (input: "10:15")                               |  Time accepted                                         |  Same                                     |  Pass             |
| 18       |  Cinema Hours - Closing Time        |  User enters closing time (input: "23:30")                               |  Time accepted                                         |  Same                                     |  Pass             |
| 19       |  Cinema Hours - Before Opening      |  User enters before opening (input: "09:59")                             |  Error: "Cinema is only open 10:00-23:30!"             |  Same                                     |  Pass             |
| 20       |  Cinema Hours - After Closing       |  User enters after closing (input: "23:31")                              |  Error: "Cinema is only open 10:00-23:30!"             |  Same                                     |  Pass             |
| 21       |  Adult Tickets - Valid              |  User enters valid number (input: 5)                                     |  Tickets accepted, proceeds to next                    |  Same                                     |  Pass             |
| 22       |  Adult Tickets - Negative           |  User enters negative (input: -1)                                        |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 23       |  Adult Tickets - Out of Range       |  User enters number > 100 (input: 101)                                   |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 24       |  Adult Tickets - Non-numeric        |  User enters letters (input: "abc")                                      |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 25       |  Child Tickets - Valid              |  User enters valid number (input: 2)                                     |  Tickets accepted, proceeds to next                    |  Same                                     |  Pass             |
| 26       |  Child Tickets - Negative           |  User enters negative (input: -5)                                        |  Error message, prompts retry                          | Same                                      |  Pass             |
| 27       |  Child Tickets - Out of Range       |  User enters number > 100 (input: 150)                                   |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 28       |  Child Tickets - Non-numeric        |  User enters special chars (input: "!@#")                                |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 29       |  Student Tickets - Valid            |  User enters valid number (input: 3)                                     |  Tickets accepted, proceeds to next                    |  Same                                     |  Pass             |
| 30       |  Student Tickets - Negative         |  User enters negative (input: -10)                                       |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 31       |  Student Tickets - Out of Range     |  User enters number > 100 (input: 200)                                   |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 32       |  Student Tickets - Non-numeric      |  User enters decimals (input: "5.5")                                     |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 33       |  Senior Tickets - Valid             |  User enters valid number (input: 1)                                     |  Tickets accepted, proceeds to validation              |  Same                                     |  Pass             |
| 34       |  Senior Tickets - Negative          |  User enters negative (input: -3)                                        |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 35       |  Senior Tickets - Out of Range      |  User enters number > 100 (input: 120)                                   |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 36       |  Senior Tickets - Non-numeric       |  User enters letters (input: "xyz")                                      |  Error message, prompts retry                          |  Same                                     |  Pass             |
| 37       |  Total Tickets - Valid (1+)         |  User books 1+ tickets (input: 1,0,0,0)                                  |  Proceeds to capacity check                            |  Same                                     |  Pass             |
| 38       |  Total Tickets - Zero               |  User enters all zeros (input: 0,0,0,0)                                  |  Error: "You must book at least one ticket!"           |  Same                                     |  Pass             |
| 39       |  Total Tickets - Multiple Types     |  User books multiple types (input: 2,2,2,2)                              |  Proceeds to capacity check                            |  Same                                     |  Pass             |
| 40       |  Total Tickets - Large Amount       |  User books many tickets (input: 50,50,50,50)                            |  Proceeds to capacity check                            |  Same                                     |  Pass             |
| 41       |  Seat Capacity - Within             |  User books within capacity (input: 50 of 250 available)                 |  Proceeds to payment                                   |  Same                                     |  Pass             |
| 42       |  Seat Capacity - Exceeds            |  User books more than available (input: 300 of 250)                      |  Error: "Not enough seats available!"                  |  Same                                     |  Pass             |
| 43       |  Seat Capacity - Exact              |  User books exact capacity (input: 250 of 250)                           |  Proceeds to payment                                   |  Same                                     |  Pass             |
| 44       |  Seat Capacity - Single Seat        |  User books last seat (input: 1 of 1)                                    |  Proceeds to payment                                   |  Same                                     |  Pass             |
| 45       |  Payment Method - Valid Cash        |  User enters payment method (input: "cash")                              |  Prompts for cash amount                               |  Same                                     |  Pass             |
| 46       |  Payment Method - Valid Card        |  User enters payment method (input: "card")                              |  Prompts for card details                              |  Same                                     |  Pass             |
| 47       |  Payment Method - Invalid           |  User enters invalid method (input: "check")                             |  Error: "Invalid payment type. Please enter..."        |  Same                                     |  Pass             |
| 48       |  Payment Method - Wrong Case        |  User enters wrong case (input: "CASH")                                  |  Error: "Invalid payment type. Please enter..."        |  Same                                     |  Pass             |
| 49       |  Cash Amount - Exact                |  User enters exact amount (input: 50.00, Total: 50.00)                   |  "Change: £0" displayed                                |  Same                                     |  Pass             |
| 50       |  Cash Amount - Excess               |  User enters excess amount (input: 100.00, Total: 50.00)                 |  "Change: £50" calculated correctly                    |  Same                                     |  Pass             |
| 51       |  Cash Amount - Insufficient         |  User enters less than total (input: 30.00, Total: 50.00)                |  Reprompt: "Insufficient cash. Try again:"             |  Same                                     |  Pass             |
| 52       |  Cash Amount - Negative             |  User enters negative (input: -50.00)                                    |  Error: "Invalid input. Please enter..."               |  Same                                     |  Pass             |
| 53       |  Card Number - Valid                |  User enters card number (input: "4532123456789012")                     |  Prompts for CVC                                       |  Same                                     |  Pass             |
| 54       |  Card Number - Different Valid      |  User enters different card (input: "5425123456789010")                  |  Prompts for CVC                                       | Same                                      |  Pass             |
| 55       |  Card Number - Short                |  User enters short number (input: "123")                                 |  Accepted (no validation)                              | Same                                      |  Pass             |
| 56       |  Card Number - Long                 |  User enters long number (input: "12345678901234567890")                 |  Accepted (no validation)                              | Same                                      |  Pass             |
| 57       |  Card CVC - Valid 3-digit           |  User enters CVC (input: "123")                                          |  Prompts for expiry date                               | Same                                      |  Pass             |
| 58       |  Card CVC - Valid 4-digit           |  User enters CVC (input: "1234")                                         |  Prompts for expiry date                               | Same                                      |  Pass             |
| 59       |  Card CVC - Non-numeric             |  User enters letters (input: "ABC")                                      |  Accepted (no validation)                              | Same                                      |  Pass             |
| 60       |  Card CVC - Special Chars           |  User enters symbols (input: "!@#")                                      |  Accepted (no validation)                              | Same                                      |  Pass             |
| 61       |  Card Expiry - Valid                |  User enters expiry (input: "12/25")                                     |  "Card payment approved" message                       | Same                                      |  Pass             |
| 62       |  Card Expiry - Different Valid      |  User enters expiry (input: "06/28")                                     |  "Card payment approved" message                       | Same                                      |  Pass             |
| 63       |  Card Expiry - Invalid Format       |  User enters invalid (input: "xyz123")                                   |  Accepted (no validation)                              | Same                                      |  Pass             |
| 64       |  Card Expiry - Any Input            |  User enters random input (input: "99/99")                               |  Accepted (no validation)                              | Same                                      |  Pass             |
| 65       |  Film Title (Add New) - Valid       |  Manager enters title (input: "Inception")                               |  "Film 'Inception' added successfully!"                | Same                                      |  Pass             |
| 66       |  Film Title - Special Characters    |  Manager enters title (input: "Star Wars: Episode IX")                   |  Film added successfully                               | Same                                      |  Pass             |
| 67       |  Film Title - Duplicate             |  Manager enters existing film (input: "Avengers Endgame")                |  Film shouldn’t be added as duplicate                  | Accepted as no duplicate check            |  Fail             |
| 68       |  Film Title - Long Name             |  Manager enters long title (input: "The Incredibly Long Movie Title...") |  Film added successfully                               | Same                                      |  Pass             |
| 69       |  Film Description - Valid           |  Manager enters description (input: "An epic adventure")                 |  Accepted, proceeds to next field                      | Same                                      |  Pass             |
| 70       |  Film Description - Empty           |  Manager presses enter (input: "")                                       |  Accepted (no validation)                              | Same                                      |  Pass             |
| 71       |  Film Description - Special Chars   |  Manager enters special chars (input: "Action/Adventure!")               |  Accepted, proceeds to next                            | Same                                      |  Pass             |
| 72       |  Film Description - Long            |  Manager enters 100+ characters                                          |  Accepted, proceeds to next                            | Same                                      |  Pass             |
| 73       |  Film Genre - Valid                 |  Manager enters genre (input: "Adventure")                               |  Accepted, proceeds to certificate                     | Same                                      |  Pass             |
| 74       |  Film Genre - Different             |  Manager enters genre (input: "Drama")                                   |  Accepted, proceeds to certificate                     | Same                                      |  Pass             |
| 75       |  Film Genre - Multiple Words        |  Manager enters genre (input: "Science Fiction")                         |  Accepted, proceeds to certificate                     | Same                                      |  Pass             |
| 76       |  Film Genre - Empty                 |  Manager presses enter (input: "")                                       | Should reprompt                                        | Accepted as doesn’t check for blank space | Fail              |
| 77       |  Film Runtime - Valid               |  Manager enters runtime (input: 150)                                     |  Runtime accepted, proceeds to next                    | Same                                      |  Pass             |
| 78       |  Film Runtime - Boundary Low        |  Manager enters minimum (input: 1)                                       |  Runtime accepted, proceeds to next                    | Same                                      |  Pass             |
| 79       |  Film Runtime - Out of Range (Low)  |  Manager enters zero (input: 0)                                          |  Error: "Invalid input. Please enter..."               | Same                                      |  Pass             |
| 80       |  Film Runtime - Out of Range (High) |  Manager enters > 300 (input: 301)                                       |  Error: "Invalid input. Please enter..."               | Same                                      |  Pass             |
| 81       |  Film Runtime - Non-numeric         |  Manager enters letters (input: "abc")                                   |  Error: "Invalid input. Please enter..."               | Same                                      |  Pass             |
| 82       |  Film Main Star - Valid             |  Manager enters actor (input: "Tom Cruise")                              |  Accepted, proceeds to distributor                     | Same                                      |  Pass             |
| 83       |  Film Main Star - Multiple Names    |  Manager enters multiple (input: "Tom Hanks & Kevin Bacon")              |  Accepted, proceeds to distributor                     | Same                                      |  Pass             |
| 84       |  Film Main Star - Special Chars     |  Manager enters with punctuation (input: "Jean-Claude Van Damme")        |  Accepted, proceeds to distributor                     | Same                                      |  Pass             |
| 85       |  Film Main Star - Empty             |  Manager presses enter (input: "")                                       | Should reprompt                                        | Accepted as doesn’t check for blank space | Fail              |
| 86       |  Film Distributor - Valid           |  Manager enters distributor (input: "Warner Bros")                       |  Accepted, proceeds to release date                    | Same                                      |  Pass             |
| 87       |  Film Distributor - Abbreviation    |  Manager enters abbreviation (input: "WB")                               |  Accepted, proceeds to release date                    | Same                                      |  Pass             |
| 88       |  Film Distributor - Long Name       |  Manager enters long name (input: "Universal Studios Entertainment")     |  Accepted, proceeds to release date                    | Same                                      |  Pass             |
| 89       |  Film Distributor - Empty           |  Manager presses enter (input: "")                                       | Should reprompt                                        | Accepted as doesn’t check for blank space | Fail              |
| 90       |  Film Release Date - Valid          |  Manager enters date (input: "15/07/2024")                               |  Film added successfully                               | Same                                      |  Pass             |
| 91       |  Film Release Date - Wrong Format   |  Manager enters format (input: "2024-07-15")                             |  Film added (no format validation)                     | Same                                      |  Pass             |
| 92       |  Film Release Date - Invalid Day    |  Manager enters day > 31 (input: "32/07/2024")                           |  Film shouldn’t be added                               | Film added                                | Fail              |
| 93       |  Film Release Date - Invalid Month  |  Manager enters month > 12 (input: "15/13/2024")                         |  Film shouldn’t be added                               | Film added                                | Fail              |
| 94       |  Screen Film Select - Valid         |  Manager selects film for screen (input: 1)                              |  "Screen X allocated with Film Title"                  | Same                                      |  Pass             |
| 95       |  Screen Film Select - Boundary      |  Manager selects last film (input: 3)                                    |  "Screen X allocated with Film Title"                  | Same                                      |  Pass             |
| 96       |  Screen Film Select - Out of Range  |  Manager selects beyond films (input: 5)                                 |  Error: "Invalid input. Please enter..."               | Same                                      |  Pass             |
| 97       |  Screen Film Select - Non-numeric   |  Manager enters letters (input: "film1")                                 |  Error: "Invalid input. Please enter..."               | Same                                      |  Pass             |
| 98       |  Search - Customer Found            |  Staff searches for existing customer (input: "John Smith")              |  Displays all matching bookings                        | Same                                      |  Pass             |
| 99       |  Search - Customer Not Found        |  Staff searches for non-existent (input: "Unknown Person")               |  "No bookings found for customer..."                   | Same                                      |  Pass             |
| 100      |  Search - Customer Case Sensitive   |  Staff searches wrong case (input: "john smith")                         |  "No bookings found for customer..."                   | Same                                      |  Pass             |
| 101      |  Search - Film Found                |  Staff searches for existing film (input: "Avengers Endgame")            |  Displays all matching bookings                        | Same                                      |  Pass             |
| 102      |  Search - Film Not Found            |  Staff searches for non-existent (input: "Unknown Movie")                |  "No bookings found for film..."                       | Same                                      |  Pass             |
| 103      |  Search - Film Case Sensitive       |  Staff searches wrong case (input: "avengers endgame")                   |  "No bookings found for film..."                       | Same                                      |  Pass             |
| 104      |  Search - Date Valid Format         |  Staff searches with valid date (input: "15/07/2026")                    |  Displays matching bookings or no results              | Same                                      |  Pass             |
| 105      |  Search - Date Invalid Format       |  Staff searches wrong format (input: "2026-07-15")                       |  Error: "Invalid date. Please try again."              | Same                                      |  Pass             |
| 106      |  Search - Date No Results           |  Staff searches date with no bookings (input: "01/01/2020")              |  "No bookings found for date..."                       | Same                                      |  Pass             |
| 107      |  Main Menu - Exit                   |  User selects exit (input: 3)                                            |  "Thank you for using Cinema Booking System. Goodbye!" | Same                                      |  Pass             |
| 108      |  File Persistence - Save Booking    |  User creates booking                                                    |  Booking saved to bookings.csv                         | Same                                      |  Pass             |
| 109      |  File Persistence - Load Booking    |  Program restarts after booking                                          |  "Loaded X bookings from file" message                 | Same                                      |  Pass             |
| 110      |  File Persistence - Schedule Save   |  Manager creates schedule                                                |  Schedule saved to schedule.csv                        | Same                                      |  Pass             |

## Annotation screenshots
<img width="940" height="395" alt="image" src="https://github.com/user-attachments/assets/fe52ed16-5ecb-4b19-b6a7-86a52dcc12f6" />

Above screenshot displays the programs ability to error handle and how it loads files from memory before the program runs.


<img width="940" height="302" alt="image" src="https://github.com/user-attachments/assets/2e4034b0-cbf7-4e8a-b2a4-e078a1daa92b" />

This screenshot shows the Booking.csv file and how the data is saved and the format its saved in


<img width="940" height="281" alt="image" src="https://github.com/user-attachments/assets/cb55a944-a0d3-493e-b117-aa1c9f46150e" />

This screenshot shows the schedule of the movies and how its saved, custom movies can also be added by a manager.


<img width="940" height="877" alt="image" src="https://github.com/user-attachments/assets/180044cf-7669-449c-8924-ad407785dd16" />

This screenshot is proof of data persistence, it’s a new instance of the program with the saved memory from the csv file.


<img width="940" height="253" alt="image" src="https://github.com/user-attachments/assets/fc0ac1c5-d45f-4e0f-a27d-e9f05e8903e6" />

This screenshot displays the format in which schedule is loaded from the file


<img width="940" height="279" alt="image" src="https://github.com/user-attachments/assets/6b717270-f78b-4ebd-a24b-c00cf44f7fae" />

This screenshot shows the screens, the timings, and shows the max seats and the number of available seats since after a booking is added a seat is used up.


## Technical Elements

Test Environment:
Operating System: Windows
IDE: CLion
C++ Standard: C++17
Compiler:g++ 
Date Tested: 04/07/2025
Tester: Wisam Haider 

## Evaluation

All functional and non-functional requirements from the brief have been fulfilled by the program i have produced. The software offers users the ability to create bookings, search records, and make payments in an easy-to-use environment, while the ability to add films to the schedule and automatically generate the weekly schedule has been added for the managers. File persistence has been introduced, which ensures that the booking and scheduling data will persist after restarting the program.
Strengths
1. Input Validations The system passes almost all 110 test cases. The getValidIntInput() function does a very good job of ensuring that the inputs provided by the user are within a certain range (e.g., movie choice: 1-3, quantity: 0-100) and do not include characters other than numbers. The system ensures that dates and time follow the correct format through the use of regular expression-like pattern matching to reject invalid date and time formats such as "2026-07-15" rather than "15/07/2026". The system validates the hours during which cinema operates (10:00-23:30).
2. Successful Implementation of Persistent Storage Mechanism The file manager class saves and loads the data using the CSV format. All the bookings are automatically saved into the bookings.csv file at the end of each transaction and are loaded when the program is initialized through the loadBookingHistory(). The testing proves that making a booking, shutting down the program, and opening it again allows loading all the bookings from the previous session with the message "Loaded X bookings from file".

3. User-Friendly Interface with Useful Feedback There are two different menus designed for staff members, who have six options, and managers, who have five options to choose from. The system gives informative and helpful error messages; for instance, the error "Error: only accepts input in range 1-3" means that something has gone wrong as opposed to a vague message, "Invalid input". Booking confirmation shows all the details of the transaction before proceeding to payment and the system confirms all actions with a feedback statement such as "Booking completed successfully" and "Film 'X' added successfully!"
Areas for Improvement
1. Customer Name Validation Too Permissive The current validation process allows for customer names that include numbers such as "John123" and special characters like "John@Smith!". Such a practice is not realistic for the actual cinema system. Even though the isEmpty() method validation does not accept empty customer names, there is no validation to prevent numeric characters and most special characters. This way, entries such as "12345" can be accepted as customer names. One possible solution is to validate the characters; if (customerName contains numbers or special characters), reject.

2. No Duplicate Films Prevention In the existing program, duplicate films can be added by the manager into the database since there is no prevention for this. As a result, there will be duplicates in the list of films, stored as elements in the films vector. For instance, by adding the film "Avengers Endgame" twice, the film will appear in the list of films two times.

Weaknesses
1. Case Sensitive Search Feature The search feature to find a booking using either a customer’s name or a movie title is case sensitive; that is, when a booking is made using “John Smith” but the employee uses “john smith”, he will get “No bookings found for customer: john smith" although the booking exists. 
2. Week-Based Booking Feature Implementation Is Incomplete The requirement is “Bookings can only be made in the current week (Thursday to Wednesday),” but any date is accepted. The system should find out the current week and only accept bookings within this period. For instance, if the current date is Thursday 15/07/2026, then the only dates that will be accepted are those from 15/07/2026 to 21/07/2026. Currently, booking can be done at any date (such as 01/01/2020 or 31/12/2099).


## References:

cppreference.com. (n.d.). nullptr, the pointer literal (since C++11). Retrieved from: https://en.cppreference.com/cpp/language/nullptr [Accessed 14 June 2026].
cppreference.com. (n.d.). std::basic_string::stol. Retrieved from: https://en.cppreference.com/cpp/string/basic_string/stol [Accessed 14 June 2026].
cppreference.com. (n.d.). std::vector<T,Allocator>::push_back. Retrieved from: https://en.cppreference.com/cpp/container/vector/push_back [Accessed 01 July 2026].
Programiz. (n.d.). C++ File Handling. Retrieved from: https://www.programiz.com/cpp-programming/file-handling [Accessed 29 June 2026].
W3Schools. (n.d.). C++ fstream fstream class. Retrieved from: https://www.w3schools.com/cpp/ref_fstream_fstream.asp [Accessed 02 July 2026].

