#ifndef HELPER_H
#define HELPER_H
#include <string>

void updatePenguranganStokOtomatis(const std::string& menu, int pengurangan);

void updatePenambahanMenuTerjualOtomatis(const std::string& menu, int penambahan);

bool foundExistingMenuPesanan(const std::string& menu);

bool foundExistingStockMenu(const std::string& menu);

int calculateTimeDifferenceInMinutes(time_t akhir, time_t awal);

#endif
