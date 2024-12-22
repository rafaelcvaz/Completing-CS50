-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Firts, I'll look at the table crime_scene_reports to look for a description of the crimes. However, I'm narrowing it down to the correct
-- time (July 28, 2023) and place (Humphrey Street) of this specific crime.
SELECT description FROM crime_scene_reports WHERE year = 2023 AND day = 28 AND month = 7 AND street = 'Humphrey Street';

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were 
--present at the time – each of their interview transcripts mentions the bakery.
--Littering took place at 16:36. No known witnesses.

-- I'll read their interviews to search for more clues.
SELECT name, transcript FROM interviews WHERE year = 2023 AND day = 28 AND month = 7;

-- Ruth witnessed a car leaving the store 10 minutes from the theft, so I'm looking for licence plates in this time frame:
SELECT id FROM people WHERE license_plate IN 
    (SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND day = 28 AND month = 7 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = 'exit');

-- This plates can belong to the suspect:
    --5P2BI95|10|16|exit
    --94KL13X|10|18|exit
    --6P58WS2|10|18|exit
    --4328GD8|10|19|exit
    --G412CB7|10|20|exit
    --L93JTIZ|10|21|exit
    --322W7JE|10|23|exit
    --0NTHK55|10|23|exit

--Suspects' id:
    --221103
    --243696
    --396669
    --398010
    --467400
    --514354
    --560886  
    --686048 

-- Eugene witnessed the thief withdrawing some money on that day's morning in 'Leggett Street'. I'll search for the name of possible suspects
SELECT id from people WHERE id IN 
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE year = 2023 AND day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));

-- Suspects' id that matches the first suspects'id list:
    --396669
    --467400
    --514354
    --686048

-- Raymond witnessed the thief calling to someone and talking for less than a minute. The thief asked this person to book a flight out of Fiftyville 
--first thing in the next morning. I'll look for the id of people that called for less than a minute on that day:
SELECT id FROM people WHERE phone_number IN 
    (SELECT caller FROM phone_calls WHERE year = 2023 AND day = 28 AND month = 7 AND duration < 60);

-- Suspects' id that matches the second suspects'id list:
    --514354
    --686048

-- I'll also look for people in the first flight of day 29. FIrst, I'll see what is the first flight out of Fiftyville.
SELECT id, hour, minute FROM flights WHERE origin_airport_id IN
    (SELECT id FROM airports WHERE city = 'Fiftyville') AND
    year = 2023 AND day = 29 AND month = 7;

-- The first flight on that day has the ID number 36 (8:20 in the morning). I'll look for passengers id's of this flight.
SELECT id FROM people WHERE passport_number IN
    (SELECT passport_number FROM passengers WHERE flight_id = 36);

-- Thief's ID = 686048

-- Where did he go to? I'll look for the destination city of that flight.
SELECT city FROM airports WHERE id IN
    (SELECT destination_airport_id FROM flights WHERE id = 36);

--The thief escaped to New York City

-- Who was the accomplice? I'll see who the thief called.
SELECT id FROM people WHERE phone_number IN
    (SELECT receiver FROM phone_calls WHERE year = 2023 AND day = 28 AND month = 7 AND duration < 60 AND caller IN
    (SELECT phone_number FROM people WHERE id = 686048));

-- Accomplice's id: 864400