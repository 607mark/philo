# 🍝 Philo - A Hungry Philosophers' Tale
👋 This is my implementation of the Dining Philosophers problem, a classic concurrency challenge in C.


The problem models a group of philosophers sitting around a table, each needing two forks to eat, with only one fork between each pair. It’s a great way to explore how to manage shared resources and prevent deadlocks in concurrent programming.

Working on this project gave me hands-on experience with multi-threading, resource synchronization, and designing solutions that avoid conflicts—essential concepts in software development involving concurrency.

## ✨ Cool Stuff Inside

- Watch philosophers think, eat, and hopefully not starve
- Real-deal multi-threading implementation (because philosophers are independent thinkers!)
- Tweakable settings so you can create your own dinner party scenarios
- Millisecond precision log of what each philosopher is up to

## 🚀 Getting Started

First things first, let's get this party started:

```bash
# Grab the code
git clone https://github.com/607mark/philo.git
cd philo

# Build it
make
```

## 🎮 How to Run It

Here's where the fun begins! Fire it up like this:

```bash
./philo [philosophers] [death_time] [eating_time] [sleeping_time] [optional: meals_needed]
```

Think of it as planning a dinner party where you decide:
- How many philosophers to invite
- How long they can go without eating (before things get... unfortunate 💀)
- How long they take to eat their spaghetti
- How long they need to sleep
- Optionally, how many meals they need to be satisfied

For example, try this:
```bash
./philo 5 800 200 200
```

This sets up a cozy dinner for 5 philosophers who need to eat every 800ms or they'll starve, take 200ms to eat, and need 200ms to sleep it off.

## 🛠️ Make It Your Own

Feel free to play around with the numbers! Want to see what happens with really hungry philosophers? Crank down that death timer! Want to simulate a lengthy Italian dinner? Bump up those eating times! The possibilities are endless.

If you run into any issues or just want to chat about concurrent programming (or actual philosophy!), feel free to open an issue. Happy coding! 🎉
