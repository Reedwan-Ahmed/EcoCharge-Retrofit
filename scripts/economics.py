#!/usr/bin/env python3
"""Reproduce EcoCharge's indicative savings/payback arithmetic.

Inputs default to values stated in the supplied presentation. This is an
assumption calculator, not a measured-performance or investment guarantee.
"""
import argparse


def calculate(daily_kwh: float, tariff: float, days: int,
              battery_saving_monthly: float, box_price: float) -> dict:
    if daily_kwh < 0 or tariff < 0 or days <= 0 or battery_saving_monthly < 0 or box_price < 0:
        raise ValueError("Inputs must be non-negative and days must be greater than zero.")
    electricity_monthly = daily_kwh * tariff * days
    combined_monthly = electricity_monthly + battery_saving_monthly
    return {
        "daily_electricity_saving_bdt": daily_kwh * tariff,
        "monthly_electricity_saving_bdt": electricity_monthly,
        "monthly_battery_saving_bdt": battery_saving_monthly,
        "monthly_combined_saving_bdt": combined_monthly,
        "payback_electricity_only_months": (box_price / electricity_monthly) if electricity_monthly else float("inf"),
        "payback_combined_months": (box_price / combined_monthly) if combined_monthly else float("inf"),
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--daily-kwh", type=float, default=3.3, help="Assumed kWh saved per vehicle per day")
    parser.add_argument("--tariff", type=float, default=11.36, help="BDT per kWh")
    parser.add_argument("--days", type=int, default=30, help="Days per month used in calculation")
    parser.add_argument("--battery-saving", type=float, default=1040.0, help="Estimated BDT/month battery-life saving")
    parser.add_argument("--box-price", type=float, default=4000.0, help="Target box price in BDT")
    args = parser.parse_args()

    result = calculate(args.daily_kwh, args.tariff, args.days,
                       args.battery_saving, args.box_price)
    print("EcoCharge indicative model — estimates only")
    print(f"Daily electricity saving:       BDT {result['daily_electricity_saving_bdt']:,.2f}")
    print(f"Monthly electricity saving:     BDT {result['monthly_electricity_saving_bdt']:,.2f}")
    print(f"Monthly battery saving:         BDT {result['monthly_battery_saving_bdt']:,.2f}")
    print(f"Combined monthly saving:        BDT {result['monthly_combined_saving_bdt']:,.2f}")
    print(f"Payback (electricity only):      {result['payback_electricity_only_months']:.2f} months")
    print(f"Payback (combined estimate):    {result['payback_combined_months']:.2f} months")
    print("\nCaution: this reproduces presentation assumptions; it is not a measured EcoCharge field result.")


if __name__ == "__main__":
    main()
