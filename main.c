/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:09:45 by sprodatu          #+#    #+#             */
/*   Updated: 2024/06/04 21:59:57 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main()
{
	int	guess_num;
	int	guess_limit;
	int	retry_limit;
	int	secret_num;

	/* Seed the random number generator */

	srand(time(NULL));
	sleep(1);

	/* Generate a random number between 1 and 10 */

	secret_num = rand() % 10 + 1;
	guess_limit = 4;
	retry_limit = 3;

	/* Loop until the user guesses the correct number */

	while (guess_limit > 0 && retry_limit > 0)
	{
		/* Prompt the user to guess a number */

		printf("Guess a number between 1 and 10: ");
		scanf("%d", &guess_num);

		/* Check if the user guessed the correct number */
		
		if (guess_num >10 || guess_num < 1)
		{
			printf("You guessed a number out of range, retry!\n");
			retry_limit--;
			if (retry_limit == 0)
			{
				printf("You have no retries left!\n");
				break;
			}
			else
				printf("You have %d retries left!\n", retry_limit);
		}
		else if (guess_num > secret_num)
		{
			printf("You guessed more than the correct number!\n");
			guess_limit--;
			printf("You have %d guesses left!\n", guess_limit);
		}
		else if (guess_num == secret_num)
		{
			printf("You guessed the correct number!\n");
			break;
		}
		else if (guess_num < secret_num)
		{
			printf("You guessed less than the correct number!\n");
			guess_limit--;
			printf("You have %d guesses left!\n", guess_limit);
		}
	}
	return (0);
}
