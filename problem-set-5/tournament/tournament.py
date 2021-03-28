# Simulate a sports tournament


import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")
    teams = [] #  list of teams | list
    # TODO: Read teams into memory from file
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file) # treating each row as a dictionary
        for team in reader:
            teams.append({
                'Team': team['team'],
                'Rating': int(team['rating'])
            })

    counts = {} # dictionary | associate team names with the number of times that team won a simulated tournament
    # TODO: Simulate N tournaments and keep track of win counts
    for n in range(N):
        winner = simulate_tournament(teams)
        counts[winner] = counts.get(winner, 0) + 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

#  # The simulate_game function accepts two teams as inputs (recall that each team is a dictionary containg the team name and the team’s rating), and simulates a game between them. If the first team wins, the function returns True; otherwise, the function returns False.
def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1['rating']
    rating2 = team2['rating']
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
    s    if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winners = teams
    while len(winners) != 1:
        winners = simulate_round(winners)
    return winners[0]['team']



if __name__ == '__main__':
    main()
