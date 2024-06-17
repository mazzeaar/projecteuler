# Readme
This repo contains my solutions to [eulers problems](https://projecteuler.net).

A new template problem can be created using 

```bash
scripts/create_problem.sh <Num>
```

## Run
First build the project using:
```bash 
mkdir build && cd build && cmake ..
```

### Run all solutions sequentially
```bash
make run
```

### Run a specific solution
```bash
make && ./main <Num>
```
Where `<N>` is the number of one of the solved problems.
