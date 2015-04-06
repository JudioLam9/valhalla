#ifndef VALHALLA_BALDR_TRANSITDEPARTURE_H_
#define VALHALLA_BALDR_TRANSITDEPARTURE_H_

#include <valhalla/baldr/graphconstants.h>

namespace valhalla {
namespace baldr {

/**
 * Information held for each departure from a transit stop. Departures within
 * a tile are ordered by the stop Id of the departure stop, followed by the
 * time of the departure.
 */
class TransitDeparture {
 public:
  /**
   * Get the edge Id - for lookup of all departures along this edge. Each edge
   * represents a unique departure/arrival stop pair and route Id.
   * @return  Returns the departure stop Id.
   */
  uint32_t edgeid() const;

  /**
   * Get the internal trip Id for this departure.
   * @return  Returns the internal trip Id.
   */
  uint32_t tripid() const;

  /**
   * Get the route Id (internal) for this departure.
   * @return  Returns the internal route Id.
   */
  uint32_t routeid() const;

  /**
   * Get the block Id oof this trip.
   * @return  Returns the block Id.
   */
  uint32_t blockid() const;

  /**
   * Get the headsign offset into the names/text list.
   * @return  Returns the offset into the names/text list.
   */
  uint32_t headsign() const;

  /**
   * Get the departure time.
   * @return  Returns the departure time in seconds from midnight.
   */
  uint32_t departure_time_() const;

  /**
   * Get the elapsed time until arrival at the next stop.
   * @return  Returns the time in seconds.
   */
  uint32_t elapsed_time() const;

  /**
   * Get the start date of this scheduled departure.
   * @return  Returns the start date (form TODO).
   */
  uint32_t start_date() const;

  /**
   * Get the end date for this scheduled departure.
   * @return  Returns the end date (form TODO).
   */
  uint32_t end_date() const;

  /**
   * Gets the days of the week for this departure.
   * @return  Returns the days of the week (form TODO)
   */
  uint32_t days() const;

  /**
   * Get the service Id (internal) for this departure.
   * Service Ids indicate use of a calendar exception rather
   * than a regular schedule.
   * @return  Returns the service Id or 0 if none.
   */
  uint32_t serviceid() const;

 protected:
  // Edge Id - lookup departures by unique edge Id (which indicates a unique
  // departure / arrival stop pair.
  uint32_t edgeid_;

  // TripId (internal).
  uint32_t tripid_;

  // Route Id (internal).
  uint32_t routeid_;

  // Block Id
  uint32_t blockid_;

  // Headsign offset into the names/text list.
  uint32_t headsign_;

  // Departure time (seconds from midnight)
  struct ScheduleTimes {
    uint32_t departure : 17;   // Seconds from midnight (86400 secs per day)
    uint32_t elapsed   : 15;   // Time until arrival at next stop
  };
  ScheduleTimes times_;

  union ScheduleDates {
    uint32_t start   : 12;     // Start date for the scheduled departure
    uint32_t end     : 12;     // End date for the scheduled departure
    uint32_t days    : 7;      // Days of the week
    uint32_t spare   : 1;
  };
  ScheduleDates dates_;

  // Service Id (internal) for calendar exceptions (additions and removals)
  uint32_t serviceid_;

  // TODO - fare info, frequencies
};

}
}

#endif  // VALHALLA_BALDR_TRANSITDEPARTURE_H_
