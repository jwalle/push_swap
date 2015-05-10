# include "push_swap.h"

void print_action(int i)
{
		if (i == 0)
			printf("sa");
		if (i == 1)
			printf("sb");
		if (i == 2)
			printf("ss");
		if (i == 3)
			printf("pa");
		if (i == 4)
			printf("pb");
		if (i == 5)
			printf("ra");
		if (i == 6)
			printf("rb");
		if (i == 7)
			printf("rr");
		printf("\n");
}

void	ft_algo(t_llist *head, t_llist *sorted, t_env *e)
{
	t_llist *current;
	int chaos[0];
	int i;
	int chaos_max;
	int order;

	while (ft_chaos(head, sorted, e))
	{
		current = head;
		ft_sa(current);
		chaos[0] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[0]);
		current = head;
		ft_sb(current);
		chaos[1] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[1]);
		current = head;
		ft_ss(current);
		chaos[2] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[2]);
		current = head;
		ft_ra(current);
		chaos[3] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[3]);
		current = head;
		ft_rb(current);
		chaos[4] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[4]);
		current = head;
		ft_pa(current);
		chaos[5] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[5]);
		/*current = head;
		ft_pb(current);
		chaos[6] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[6]);
		current = head;
		ft_rr(current);
		chaos[7] = ft_chaos(current, sorted, e);
		printf("%d\n", chaos[7]);*/
		i = 0;
		chaos_max = 100;
		order = 0;
		while (i < 7)
		{
			if (chaos_max > chaos[i])
			{
				chaos_max = chaos[i];
				order = i;
			}
			i++;
		}
		printf("order = %d\n", order);
		if (order == 0)
			ft_sa(head);
		if (order == 1)
			ft_sb(head);
		if (order == 2)
			ft_ss(head);
		if (order == 3)
			ft_ra(head);
		if (order == 4)
			ft_rb(head);
		if (order == 5)
			ft_pa(head);
		if (order == 6)
			ft_pb(head);
		if (order == 7)
			ft_rr(head);
		print_action(order);
		print_list(head);
		printf("chaos = %d\n\n", ft_chaos(head, sorted, e));
	}
}
