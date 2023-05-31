class UndergroundSystem(object):

    def __init__(self):
        self.ids = {}
        self.stations = {}
        

    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.ids[id] = [stationName,t]
        if stationName not in self.stations:
            self.stations[stationName] = defaultdict(list)

    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        station1, t1 = self.ids.pop(id)
        self.stations[station1][stationName].append(t-t1)

    def getAverageTime(self, start, end):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        return float(sum(self.stations[start][end]))/float(len(self.stations[start][end]))


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)