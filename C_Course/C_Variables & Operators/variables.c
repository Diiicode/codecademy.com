/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:46:19 by diserra           #+#    #+#             */
/*   Updated: 2025/09/03 15:47:43 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main() {

int appleQuantity;
float applePrice = 1.49;
double appleReview;
int appleReviewDisplay;
const char appleLocation = 'F';

appleQuantity = 23;
appleReview = 82.5;
appleReviewDisplay = (int)(appleReview);

// Put all your code above this and if you declare your variables using the given names and types there is no need to change any of the code below.
printf("An apple costs: $%.2f, there are %d in inventory found in section: %c and your customers gave it an average review of %d%%!", applePrice, appleQuantity, appleLocation, appleReviewDisplay);

}