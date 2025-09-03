/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:47:34 by diserra           #+#    #+#             */
/*   Updated: 2025/09/03 15:47:40 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void) {
    // Example starting data
    int appleQuantity = 12;

    // (3) Track the day of the week; 0 = first day
    int dayOfWeek = 0;

    // (4) Add any number of days BEFORE the if block
    dayOfWeek += 3;  // change this as you like

    // (2) Compute review average from 823 total over 9 reviewers
    double totalScore = 823.0;
    int reviewers = 9;
    double appleReview = totalScore / reviewers;  // 91.444...

    // (6) New review of 52 came in; update totals and recompute
    totalScore += 52.0; // 823 + 52 = 875
    reviewers += 1;     // 9 + 1 = 10
    appleReview = totalScore / reviewers; // 875 / 10 = 87.5

    // Cast to display as an integer score
    int appleReviewDisplay = (int)appleReview;

    printf("Average review: %.2f (displayed as %d)\n",
           appleReview, appleReviewDisplay);

    // (1) + (5) Offer a sale if low stock OR it's the 4th day (index 3)
    if (dayOfWeek % 7 == 3 || appleQuantity < 10) {
        printf("Sale on apples today!\n");
    } else {
        printf("Regular pricing today.\n");
    }

}