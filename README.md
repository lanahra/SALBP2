# SALBP-2 - Simulated Annealing

Simulated annealing heuristic implementation for the Simple Assembly Line Balancing Problem type 2 (SALBP-2)

## Installation

  Clone repository and compile binary:

  ```
  git clone https://github.com/lanahra/SALBP2.git
  cd SALBP2/simulated-annealing
  make
  ```

## Usage

  Run the command:

  ```
  ./salbp2-sa INSTANCE WORKSTATIONS SEED STEPS
      INSTANCE instance file
      WORKSTATION fixed number of workstations
      SEED seed for random number generation
      STEPS number of iterations
  ```

  Or run the ```solve.sh``` script containing preset parameters.
