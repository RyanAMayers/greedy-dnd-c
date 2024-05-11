#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct coins {
  unsigned int copper;
  unsigned int silver;
  unsigned int electrum;
  unsigned int gold;
  unsigned int platinum;
};

// Each coin denomination's value relative to cp.
const struct coins denoms = {1, 10, 50, 100, 1000};

unsigned long
toCopper(unsigned long qty, int mult) {
  return qty * mult;
};

struct coins *init(void) {
  struct coins *purse = malloc(sizeof *purse);
  printf("\n\n");

  printf("How much copper do you have?    > ");
  scanf("%u", &purse->copper);

  printf("How much silver do you have?    > ");
  scanf("%u", &purse->silver);

  printf("How much electrum do you have?  > ");
  scanf("%u", &purse->electrum);

  printf("How much gold do you have?      > ");
  scanf("%u", &purse->gold);

  printf("How much platinum do you have?  > ");
  scanf("%u", &purse->platinum);

  return purse;
};

int printPurse(struct coins *purse) {
  printf("\n\n");
  printf("PURSE VALUES:\n");
  printf("CU: %u\n", purse->copper);
  printf("AG: %u\n", purse->silver);
  printf("EL: %u\n", purse->electrum);
  printf("AU: %u\n", purse->gold);
  printf("PT: %u\n\n", purse->platinum);
  return 0;
}

unsigned long coinsToWealth(struct coins *purse) {
  unsigned long copperWealth = 0;
  printf("Converting coins to wealth...\n\n");
  printf("%lu CU + %u CU\n", copperWealth, purse->copper);
  copperWealth += purse->copper;
  printf("=%luCU\n\n", copperWealth);
  printf("%lu CU + %u AG\n", copperWealth, purse->silver * denoms.silver);
  copperWealth += (purse->silver * denoms.silver);
  printf("=%luCU\n\n", copperWealth);
  printf("%lu CU + %u EL\n", copperWealth, purse->electrum * denoms.electrum);
  copperWealth += (purse->electrum * denoms.electrum);
  printf("=%luCU\n\n", copperWealth);
  printf("%lu CU + %u AU\n", copperWealth, purse->gold * denoms.gold);
  copperWealth += (purse->gold * denoms.gold);
  printf("=%luCU\n\n", copperWealth);
  printf("%lu CU + %u PT\n", copperWealth, purse->platinum * denoms.platinum);
  copperWealth += (purse->platinum * denoms.platinum);
  printf("=%luCU\n\n", copperWealth);
  return copperWealth;
}

unsigned long printWealth(struct coins *purse) {
  unsigned long copperWealth = coinsToWealth(purse);
  printf("\n\n");
  printf("Total Wealth in Copper: %i\n", copperWealth);
  return copperWealth;
};

struct coins *wealthToCoins(unsigned long copperWealth) {
  struct coins *outPurse = malloc(sizeof *outPurse);
  printf("\n\n");
  printf("Converting wealth to coins...\n\n");
  printf("STARTING WEALTH:\n");
  printf("Total Wealth in Copper: %lu\n", copperWealth);
  unsigned long remainder;

  printf("\n\n");
  remainder = copperWealth % denoms.platinum;
  outPurse->platinum = (copperWealth - remainder) / denoms.platinum;
  printf("%lu CU -> %u PT (%lu CU rem.) - Adding to purse...\n", copperWealth, outPurse->platinum, remainder);
  copperWealth = remainder;


  remainder = copperWealth % denoms.gold;
  outPurse->gold = (copperWealth - remainder) / denoms.gold;
  printf("%lu CU -> %u AU (%lu CU rem.) - Adding to purse...\n", copperWealth, outPurse->gold, remainder);
  copperWealth = remainder;

  // we're skipping electrum because it's stupid
  printf("Skipping electrum...\n");

  remainder = copperWealth % denoms.silver;
  outPurse->silver = (copperWealth - remainder) / denoms.silver;
  printf("%lu CU -> %u AG (%lu CU rem.) - Adding to purse...\n", copperWealth, outPurse->silver, remainder);
  outPurse->copper = remainder;

  printf("%lu CU remaining - Adding to purse...\n", copperWealth, outPurse->platinum, remainder);
  return outPurse;
}

int main(void) {
  struct coins *purse = init();
  printPurse(purse);
  unsigned long wealth = coinsToWealth(purse);
  struct coins *newPurse = wealthToCoins(wealth);
  printWealth(newPurse);
  printPurse(newPurse);
  free(purse);
  return 0;
};
